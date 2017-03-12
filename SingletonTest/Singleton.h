
#define SingletonH(methodName)  +(instancetype)share##methodName;

#if __has_feature(objc_arc)
#define SingletonM(methodName)\
static id _instance = nil;\
+(instancetype)allocWithZone:(struct _NSZone *)zone{\
    if(_instance == nil){\
        static dispatch_once_t onceToken;\
        dispatch_once(&onceToken, ^{\
            _instance = [super allocWithZone:zone];\
        });\
    }\
    return _instance;\
}\
\
+ (instancetype)share##methodName{\
    return [[self alloc]init];\
}\
\
- (instancetype)init {\
    static dispatch_once_t onceToken;\
    dispatch_once(&onceToken, ^{\
        _instance = [super  init];\
    });\
    return _instance;\
}\
\
+ (instancetype)copyWithZone:(struct _NSZone *)zone{\
    return _instance;\
}\
\
+ (instancetype)mutableCopyWithZone:(struct _NSZone *)zone{\
    return _instance;\
}\
\
- (instancetype)copyWithZone:(struct _NSZone *)zone{\
    return _instance;\
}\
\
- (instancetype)mutableCopyWithZone:(struct _NSZone *)zone{\
    return _instance;\
}
#else
#define SingletonM(methodName)\
static id _instance = nil;\
+(instancetype)allocWithZone:(struct _NSZone *)zone{\
    if(_instance == nil){\
    static dispatch_once_t onceToken;\
    dispatch_once(&onceToken, ^{\
    _instance = [super allocWithZone:zone];\
      });\
    }\
    return _instance;\
}\
\
+ (instancetype)share##methodName{\
    return [[self alloc]init];\
}\
\
- (instancetype)init {\
    static dispatch_once_t onceToken;\
    dispatch_once(&onceToken, ^{\
    _instance = [super  init];\
       });\
    return _instance;\
}\
\
+ (instancetype)copyWithZone:(struct _NSZone *)zone{\
    return _instance;\
}\
\
+ (instancetype)mutableCopyWithZone:(struct _NSZone *)zone{\
    return _instance;\
}\
\
- (instancetype)copyWithZone:(struct _NSZone *)zone{\
    return _instance;\
}\
\
- (instancetype)mutableCopyWithZone:(struct _NSZone *)zone{\
    return _instance;\
}\
- (NSUInteger)retainCount{\
    return 1;\
}\
\
- (oneway void)release{\
  \
}\
- (id)retain{\
    return _instance;\
}
#endif





