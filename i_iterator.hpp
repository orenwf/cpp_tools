#ifndef I_ITERATOR_HPP
#define I_ITERATOR_HPP
namespace tools {

template <typename T>
class i_iterator
{
    virtual const T& begin() = 0;
    virtual const T& getNext() = 0;
    virtual bool hasNext() = 0;
    virtual const T& end() = 0;

} // namespace tools
#endif
