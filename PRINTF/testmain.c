#include <stdio.h>

int main(void)
{
	int	i;

	i = 4;
	ft_printf("%.12d\n", 123);
	printf("%.12d\n", 123);
	ft_printf("%s\n", "hei moi jee");
	printf("%s\n", "hei moi jee");
	ft_printf("%p\n", &i);
	printf("%p\n", &i);
	ft_printf("%%\n");
	printf("%%\n");
	ft_printf("%+d, %+d, %-5d\n", -4, 21, 56);
	printf("%+d, %+d, %-5d\n", -4, 21, 56);
	ft_printf("%%i: %i | %%o: %o | %%u: %u | %%x: %#x | %%X: %X | %%c: %c\n", 5, 9, 12, 45, 21455, 'a');
	printf("%%i: %i | %%o: %o | %%u: %u | %%x: %#x | %%X: %X | %%c: %c\n", 5, 9, 12, 45, 21455, 'a');
	ft_printf("lol%c lol% d %c %c %012d %#o\n", 'b', 1234, 'h', 'k', 9871, 6382);
	printf("lol%c lol% d %c %c %012d %#o\n", 'b', 1234, 'h', 'k', 9871, 6382);
	ft_printf("%lld | %llo | %llu | %llx | %llX\n", (long long)431, (unsigned long long)2234693, (unsigned long long)4564562093, (unsigned long long)3744546651, (unsigned long long)5456737);
	printf("%lld | %llo | %llu | %llx | %llX\n", (long long)431, (unsigned long long)2234693, (unsigned long long)4564562093, (unsigned long long)3744546651, (unsigned long long)5456737);
	ft_printf("%.20f | %lf | %Lf\n", 0.7, 76.6378292, (long double)725674.72646);
	printf("%.20f | %lf | %Lf\n", 0.7, 76.6378292, (long double)725674.72646);
	return (0);
}
