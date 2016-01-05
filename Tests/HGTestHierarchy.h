#import <Foundation/Foundation.h>


@interface HGRootClass : NSObject

@end


@interface HGDescendant1 : HGRootClass

- (void)methodDefinedInDescendant1;

@end


@interface HGDescendant2 : HGRootClass

@end


@interface HGDescendant1Descendant1 : HGDescendant1

+ (void)classMethodDefinedInDescendant1Descendant1;
- (void)methodDefinedInDescendant1Descendant1;

@end


@interface HGDescendant1Descendant2 : HGDescendant1

@end


@interface HGPropertyClass : NSObject

@property (nonatomic, readonly, copy) NSString *property1;
@property (atomic, readwrite, weak) id property2;
@property (setter=setFoo:, getter=getBar) BOOL baz;

@end


@interface HGInstanceVariableClass : NSObject {
	id publicIvar;
}

@property (nonatomic, readonly) id propertyWithoutIvar;
@property id propertyWithIvar;
@property id propertyWithSynthesizedIvar;

@end


@interface HGTypeTestClass : NSObject

@property NSString *stringProperty;
@property id idProperty;
@property Class classProperty;
@property char charProperty;
@property int intProperty;
@property _Bool boolProperty;

@end