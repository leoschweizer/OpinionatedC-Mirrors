#import "HGInstanceVariableMirror.h"
#import "HGInstanceVariableMirror-Runtime.h"
#import "HGTypeMirrors.h"


@interface HGInstanceVariableMirror ()

@property (nonatomic, readonly) Ivar mirroredInstanceVariable;

@end


@implementation HGInstanceVariableMirror

- (instancetype)initWithDefiningClass:(HGClassMirror *)definingClass instanceVariable:(Ivar)instanceVariable {
	if (self = [super init]) {
		_mirroredInstanceVariable = instanceVariable;
		_definingClass = definingClass;
		_name = [NSString stringWithUTF8String:ivar_getName(_mirroredInstanceVariable)];
	}
	return self;
}

- (HGTypeMirror *)type {
	const char *encoding = ivar_getTypeEncoding(self.mirroredInstanceVariable);
	return [HGTypeMirror createForEncoding:[NSString stringWithUTF8String:encoding]];
}

@end
