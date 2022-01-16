#include <utility>

template <class Type, class Name>
class Named
{
public:
    template<class... Args>
    explicit Named(Args&&... args) 
        : type(std::forward<Args>(args)...) 
    {}

    operator Type& () { return type; }

    Type& get() { return type; }

private:
    Type type;
};
