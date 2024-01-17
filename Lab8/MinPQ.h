#pragma once

#ifndef MINPQ_H
#define MINPQ_H

template<class T>

class MinPQ
{
public:
	virtual ~MinPQ();
	virtual bool IsEmpty() const = 0;
	virtual T Top() const = 0;
	virtual void Push(const T&) = 0;
	virtual void Pop() = 0;
};

#endif