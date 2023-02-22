#include <stdio.h>
#include <iostream>
class s
{
	int	d;
public:
void  get(int i)
{
	d = i;
	printf("the adress in get  %p\n", &d);
}
int i;
int di()
{
	return d;
}
	void fun()
	{
		printf("%d\n",i);
//	printf("the adress in get  %p\n", &d);

	};
}t;

int main()
{

	//t.get(99);
	t.fun();
	t.d = 5;
	printf("\n%d\n", t.d);
}