#include "lem_in.h"
#include <stdio.h>
#include <limits.h>

int		parse_data(t_lem_in *m)
{
	char	*line;
	int		len;
	int		i;

	i = 0;
	m->nbants = -1;
	get_next_line(0, &line);
	len = ft_strlen(line);
	while (len <= 10 && line[i])
		if (ft_isdigit(line[i]))
			i++;
		else
			return (0);
	if (len <= 10)
		m->nbants = ft_atoi(line);
	if (m->nbants == 0 && len > 10)
		return (0);
	return (1);
}

int	main()
{
	double r1;
	double r2;
	double r3;
	double res;
	char p;

	res = 0;
	r1 = 0;
	r2 = 0;
	r3 = 0;

	printf("Entrer type de branchement (s/p)\n");
	scanf("%c", &p);
	printf("Entrer les tois resistance \n");
	scanf("%lf%lf%lf", &r1, &r2, &r3);

	if (p == 's')
	{
		res = (r1 + r2 + r3);
	}
	else if (p == 'p')
	{
		res = (r1 * r2 * r3) / ((r1 * r2) + (r1 * r3) + (r2 * r3));
	}
	printf("Le resultat est : %lf.\n", res);
	return (0);
}
