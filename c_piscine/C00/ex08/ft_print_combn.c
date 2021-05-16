
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
	}
}

void	ft_print_combn(int n)
{
	int i;
	int max;
	max = 999;
	
	while (i < max)
	{
		ft_putnbr(i);
		write(1, ", ", 2);
		i++;
	}

}
