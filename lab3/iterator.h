#ifndef ALGORITHMS_ITERATOR_H
class Iterator 
{
	public:
		virtual int next() = 0;
		virtual bool has_next() = 0;
};
#define ALGORITHMS_ITERATOR_H
#endif //ALGORITHMS_ITERATOR_H