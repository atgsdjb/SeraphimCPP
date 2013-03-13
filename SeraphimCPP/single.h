#ifndef  _SERAPHIM_SINGLE
#define  _SERAPHIM_SINGLE
namespace seraphim{
	class single
	{
		int d;
		single* next;
	public:
		single(int _d,single* _next){d=_d;next=_next;}
		int getData(){return d;}
		single* getNext(){return next;}
		void setNext(single* _next){this->next = _next;}
		~single(void);
	};
};
#endif
#pragma once

