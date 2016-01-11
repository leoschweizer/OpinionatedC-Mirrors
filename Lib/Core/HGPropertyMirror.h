#import <Foundation/Foundation.h>


@class HGClassMirror;
@class HGProtocolMirror;
@class HGInstanceVariableMirror;
@class HGMethodMirror;
@protocol HGTypeMirror;


typedef NS_OPTIONS(NSUInteger, HGPropertyAttributes) {
	HGPropertyAttributesNone                = 0,
	HGPropertyAttributesReadonly            = 1 << 0,
	HGPropertyAttributesCopy                = 1 << 1,
	HGPropertyAttributesRetain              = 1 << 2,
	HGPropertyAttributesNonatomic           = 1 << 3,
	HGPropertyAttributesDynamic             = 1 << 4,
	HGPropertyAttributesWeak                = 1 << 5,
	HGPropertyAttributesGarbageCollection   = 1 << 6
};


@interface HGPropertyMirror : NSObject

/**
 * The HGClassMirror reflecting the receiver's mirrored propertie's defining class.
 * This value is only set when retrieving properties defined by a class.
 */
@property (nonatomic, readonly) HGClassMirror *definingClass;

/**
 * The HGProtocolMirror reflecting the receiver's mirrored propertie's defining protocol.
 * This value is only set when retrieving properties defined by a protocol.
 */
@property (nonatomic, readonly) HGProtocolMirror *definingProtocol;

/**
 * The attributes of the receiver's mirrored property (see HGPropertyAttributes).
 */
@property (nonatomic, readonly) HGPropertyAttributes attributes;

/**
 * The HGTypeMirror reflecting the receiver's mirrored propertie's type.
 */
@property (nonatomic, readonly) id<HGTypeMirror> type;


/**
 * Answers an HGInstanceVariableMirror reflecting the instance variable backing
 * the receiver's mirrored property.
 */
- (HGInstanceVariableMirror *)backingInstanceVariable;

/**
 * Answers an HGMethodMirror reflecting the receiver's mirrored propertie's 
 * getter method.
 */
- (HGMethodMirror *)getter;

/**
 * Answers YES when the receiver's mirrored property is a copy of the value 
 * last assigned (copy).
 */
- (BOOL)isCopied;

/**
 * Answers YES when the receiver's mirrored proeprty is is dynamic (@dynamic).
 */
- (BOOL)isDynamic;

/**
 * Answers YES when the receiver's mirrored property is non-atomic (nonatomic).
 */
- (BOOL)isNonatomic;

/**
 * Answers YES when the receiver's mirrored property is read-only (readonly).
 */
- (BOOL)isReadonly;

/**
 * Answers YES when the receiver's mirrored property is a reference to the
 * value last assigned (retain).
 */
- (BOOL)isRetained;

/**
 * Answers YES when the receiver's mirrored property is a weak reference (__weak).
 */
- (BOOL)isWeak;

/**
 * Answers YES when the receiver's mirrored property is eligible for 
 * garbage collection.
 */
- (BOOL)isGarbageCollected;

/**
 * Answers the name of the receiver's mirrored property.
 */
- (NSString *)name;

/**
 * Answers an HGMethodMirror reflecting the receiver's mirrored propertie's
 * setter method.
 */
- (HGMethodMirror *)setter;

@end
