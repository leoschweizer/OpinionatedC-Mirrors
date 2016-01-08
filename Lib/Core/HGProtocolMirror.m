#import "HGProtocolMirror.h"
#import <objc/runtime.h>
#import "HGMethodDescriptionMirror-Runtime.h"


@implementation HGProtocolMirror

+ (NSArray *)allProtocols {
	unsigned int protocolCount;
	Protocol * __unsafe_unretained *protocols = objc_copyProtocolList(&protocolCount);
	NSMutableArray *result = [NSMutableArray arrayWithCapacity:protocolCount];
	for(int i = 0; i < protocolCount; i++) {
		[result addObject:[[self alloc] initWithProtocol:protocols[i]]];
	}
	free(protocols);
	return [NSArray arrayWithArray:result];
}

- (instancetype)initWithProtocol:(Protocol *)aProtocol {
	if (self = [super init]) {
		_mirroredProtocol = aProtocol;
	}
	return self;
}

- (NSArray *)adoptedProtocols {
	NSMutableArray *result = [NSMutableArray array];
	unsigned int protocolCount = 0;
	Protocol * __unsafe_unretained *protocols = protocol_copyProtocolList(self.mirroredProtocol, &protocolCount);
	for (int i = 0; i < protocolCount; i++) {
		Protocol *protocol = protocols[i];
		HGProtocolMirror *mirror = [[HGProtocolMirror alloc] initWithProtocol:protocol];
		[result addObject:mirror];
	}
	free(protocols);
	return [NSArray arrayWithArray:result];
}

- (NSArray *)getMethods:(BOOL)isInstanceMethod {
	unsigned int requiredMethodCount;
	unsigned int optionalMethodCount;
	struct objc_method_description *requiredMethods = protocol_copyMethodDescriptionList(self.mirroredProtocol, YES, isInstanceMethod, &requiredMethodCount);
	struct objc_method_description *optionalMethods = protocol_copyMethodDescriptionList(self.mirroredProtocol, NO, isInstanceMethod, &optionalMethodCount);
	NSMutableArray *result = [NSMutableArray arrayWithCapacity:requiredMethodCount + optionalMethodCount];
	for (int i = 0; i < requiredMethodCount; i++) {
		struct objc_method_description description = requiredMethods[i];
		HGMethodDescriptionMirror *mirror = [[HGMethodDescriptionMirror alloc] initWithDefiningProtocol:self methodDescription:description isRequired:YES isInstanceMethod:isInstanceMethod];
		[result addObject:mirror];
	}
	for (int i = 0; i < optionalMethodCount; i++) {
		struct objc_method_description description = optionalMethods[i];
		HGMethodDescriptionMirror *mirror = [[HGMethodDescriptionMirror alloc] initWithDefiningProtocol:self methodDescription:description isRequired:NO isInstanceMethod:isInstanceMethod];
		[result addObject:mirror];
	}
	return result;
}

- (NSArray *)instanceMethods {
	return [self getMethods:YES];
}

- (NSArray *)classMethods {
	return [self getMethods:NO];
}

@end
