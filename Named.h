#include <utility>

#define NAMED(Name, Type) using Name = Named<Type, struct _Name>

template <class Type, class Name>
class Named
{
public:
     template<class... Args>
     constexpr explicit Named(Args&&... args)
         : type(std::forward<Args>(args)...)
     {}

    constexpr operator Type& () { return type; }

    constexpr Type* operator-> () { return &type; }
    constexpr const Type* operator-> () const { return &type; }

    constexpr Type& operator* () { return type; }
    constexpr const Type& operator* () const { return type; }

    constexpr Type& get() { return type; }

private:
    Type type;
};
