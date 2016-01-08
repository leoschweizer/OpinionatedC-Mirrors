#import <Foundation/Foundation.h>


@class HGInstanceVariableMirror;
@class HGMethodMirror;
@class HGPropertyMirror;


@interface HGClassMirror : NSObject <NSCopying>

/**
 * Answers an NSArray of HGClassMirrors reflecting all the known classes of
 * the current runtime environment.
 */
+ (NSArray *)allClasses;

/**
 * The mirrored class.
 */
@property (nonatomic, readonly) Class mirroredClass;

/**
 * Answers an HGClassMirror instance reflecting aClass.
 */
- (instancetype)initWithClass:(Class)aClass;

/**
 * Creates an instance variable named aName in the receiver's mirrored class.
 * @returns an HGInstanceVariableMirror reflecting the newly added instance variable.
 */
- (HGInstanceVariableMirror *)addInstanceVariableNamed:(NSString *)aName withEncoding:(const char *)anEncoding;

/**
 * Creates a method in the receiver's mirrored class.
 * @returns an HGMethodMirror reflecting the newly created method.
 */
- (HGMethodMirror *)addMethodNamed:(SEL)aSelector withImplementation:(IMP)anImplementation andEncoding:(const char *)anEncoding;

/**
 * Creates a subclass of the receiver's mirrors class with the name aClassName.
 * @return a HGClassMirror instance reflecting the newly created class.
 * @note The created class will not be registered in order to allow adding 
 *  instance variables. Call [aClassMirror registerClass] to finalize the class 
 *  creation process.
 */
- (HGClassMirror *)addSubclassNamed:(NSString *)aClassName;

/**
 * Answers an NSArray of OCProtocolMirrors reflecting the protocols adopted
 * by the receiver's mirrored class.
 */
- (NSArray *)adoptedProtocols;

/**
 * Answers an NSArray of HGClassMirrors reflecting the receiver's mirrored subclasses
 * and the receiver's descendant's subclasses.
 */
- (NSArray *)allSubclasses;

/**
 * Answers an NSArray of HGClassMirrors reflecting the receiver's superclasses,
 * in the order of the inheritance chain.
 */
- (NSArray *)allSuperclasses;

/**
 * Answers an HGClassMirror reflecting the class of the receiver's mirrored 
 * class (that is, the metaclass).
 */
- (HGClassMirror *)classMirror;

/**
 * Answers an NSArray of HGInstanceVariableMirror instances reflecting the 
 * instance variables defined by the receiver's mirrored class.
 */
- (NSArray *)instanceVariables;

/**
 * Answers an HGInstanceVariableMirror reflecting the instance variable named
 * aName.
 */
- (HGInstanceVariableMirror *)instanceVariableNamed:(NSString *)aName;

/**
 * Answers YES if the mirrored class is a metaclass, otherwise NO.
 */
- (BOOL)isMetaclass;

/**
 * Answers an NSDictionary mapping selector names to HGMethodMirror instances
 * reflecting the methods defined by the receiver's mirrored class.
 */
- (NSArray *)methods;

/**
 * Answers an HGMethodMirror reflecting the method with the selector aSelector.
 */
- (HGMethodMirror *)methodNamed:(SEL)aSelector;

/**
 * Answers the name of the receiver's mirrored class.
 */
- (NSString *)name;

/**
 * Answers an NSArray of HGPropertyMirror instances reflecting the properties 
 * defined by the receiver's mirrored class.
 */
- (NSArray *)properties;

/**
 * Answers an HGPropertyMirror reflecting the property named aName.
 */
- (HGPropertyMirror *)propertyNamed:(NSString *)aName;

/**
 * Registeres the receiver's mirrored class. Call this after creating a new class
 * to finalize the class creation process.
 */
- (void)registerClass;

/**
 * Answers an NSArray of HGClassMirrors reflecting the siblings of the receiver's
 * mirrored class.
 */
- (NSArray *)siblings;

/**
 * Answers an NSArray of HGClassMirrors reflecting the receiver's mirrored subclasses.
 */
- (NSArray *)subclasses;

/**
 * Answers an HGClassMirror reflecting the receiver's mirrored superclass.
 */
- (HGClassMirror *)superclass;

/**
 * Compares the receiving HGClassMirror to another HGClassMirror.
 * @returns YES if the mirrored class of aClassMirror is euqal to the receiver's
 * mirrored class.
 */
- (BOOL)isEqualToClassMirror:(HGClassMirror *)aClassMirror;

@end
