#ifndef __SINGLETON_H_
#define __SINGLETON_H_

template <typename _Tp>
class SingletonT
{
public:
	static _Tp* GetInstance()
	{
		static _Tp instance;
		return &instance;
	}

protected:
	SingletonT() {}
	~SingletonT() {}
};

#endif //__SINGLETON_H_