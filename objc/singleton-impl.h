// I got this from…somehwere and modified it.  I've long since forgotten
// where or when.

#define SINGLETON_IMPLEMENTATION(classname, instancename)                   \
    static classname *instancename##_ = nil;                                \
                                                                            \
    + (classname*) instancename                                             \
    {                                                                       \
        @synchronized(self)                                                 \
        {                                                                   \
            if (instancename##_ == nil)                                     \
            {                                                               \
                [[self alloc] init];                                        \
            }                                                               \
        }                                                                   \
                                                                            \
        return instancename##_;                                             \
    }                                                                       \
                                                                            \
    + (id)allocWithZone:(NSZone *)zone                                      \
    {                                                                       \
        @synchronized(self)                                                 \
        {                                                                   \
            if (instancename##_ == nil)                                     \
            {                                                               \
                instancename##_ = [super allocWithZone:zone];               \
                return instancename##_;                                     \
            }                                                               \
        }                                                                   \
                                                                            \
        return nil;                                                         \
    }                                                                       \
                                                                            \
    - (id)copyWithZone:(NSZone *)zone                                       \
    {                                                                       \
        return self;                                                        \
    }                                                                       \
                                                                            \
    - (id)retain                                                            \
    {                                                                       \
        return self;                                                        \
    }                                                                       \
                                                                            \
    - (NSUInteger)retainCount                                               \
    {                                                                       \
        return NSUIntegerMax;                                               \
    }                                                                       \
                                                                            \
    - (void)release                                                         \
    {                                                                       \
    }                                                                       \
                                                                            \
    - (id)autorelease                                                       \
    {                                                                       \
        return self;                                                        \
    }
