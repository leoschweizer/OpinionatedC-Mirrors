#import "OCTestHierarchy.h"


@implementation OCRootClass

@end


@implementation OCDescendant1

- (void)methodDefinedInDescendant1 {}

@end


@implementation OCDescendant2

@end


@implementation OCDescendant1Descendant1

+ (void)classMethodDefinedInDescendant1Descendant1 {}
- (void)methodDefinedInDescendant1Descendant1 {}

@end


@implementation OCDescendant1Descendant2

@end


@implementation OCPropertyClass

@end


@implementation OCInstanceVariableClass {
	id privateIvar;
}

@synthesize propertyWithSynthesizedIvar = _propertyWithSynthesizedIvarBaz;

- (id)propertyWithoutIvar {
	return nil;
}

@end
