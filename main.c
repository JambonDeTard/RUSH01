/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 10:18:35 by avillard          #+#    #+#             */
/*   Updated: 2022/08/20 10:18:37 by avillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>
#include<stdlib.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (*str)
    {
        i++;
    }
    return (i);
}

int comp_global(int * input, int * tab)
{
    int line_ck;
    int col_ck;

    line_ck = comp_line(tab, input, 0);
    col_ck = col(tab, input);
    if (line_ck == 1 && col_ck == 1)
        return (1);
    else
        return (0);
}

int comp_line(int * tab, int * input, int diff)
{
    int index;
    int j;
    int min;
    int max;
    int countleft;
    int countright;

    max = 0;
    min = 0;
    countleft = 0;
    countright = 0;
    index = 0;
    j = 0;
    while (j < 4)
    {
        while (index < 4)
        {
            if (tab[index][j] > max)
            {
                max = tab[index][j];
                countleft++;
            }
            if (tab[3-index][j] > min)
            {
                min = tab[3 - index][j];
                countright++;
            }
        }
            
    }
}

int col(int * tab, int * input)
{
    int *col[4][4];
    int i;
    int j;

    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            col[i][j] = tab[j][i];
            j++;
        }
        i++;
    }
    return (comp_line(col, input, 1))
}

void    ft_putstr(char *str)
{
    while (*str)
        ft_putchar(*str++);
}

int check(int index, int * possibilite, int * input)
{
    int i;
    int result;

    i = 0;
    if (index == 4)
    {
        result = comp_global(input, tab);
    }
    while (i < 24)
    {
        int *tab[index] = possibilite[i];
        if (check(index + 1, possibilite, input) == 1)
            return (1);
        i++;
    }
}

int main(int ac, char **av)
{
    int i;
    int j;
    int * entrees;
    int	possibility[24][4] = {{1, 2, 3, 4}, {1, 2, 4, 3}, {1, 3, 4, 2},
	{1, 3, 2, 4}, {1, 4, 3, 2}, {1, 4, 2, 3},
	{2, 1, 3, 4}, {2, 1, 4, 3}, {2, 3, 1, 4},
	{2, 3, 4, 1}, {2, 4, 3, 1}, {2, 4, 1, 3},
	{3, 1, 2, 4}, {3, 1, 4, 2}, {3, 2, 1, 4},
	{3, 2, 4, 1}, {3, 4, 2, 1}, {3, 4, 1, 2},
	{4, 1, 2, 3}, {4, 1, 3, 2}, {4, 2, 3, 1},
	{4, 2, 1, 3}, {4, 3, 1, 2}, {4, 3, 2, 1}};
    
    entrees = NULL;
    
    if (ac != 2) //VERIFIE LES VALEURS ENVOYES VIA LAMCEMENT DE PROGRAMME
    {
        ft_putstr("Error\n");
        return (0);
    }
    if (ft_strlen(av[1]) != 31)
    {
        ft_putstr("Error\n");
        return (0);
    }//recuperer les valeurs envoyees par le lancement du main de char en int 
    av[1] = (char *)malloc(sizeof(int) * 16);//int * car malloc est normalement un void *
    if (!(av[1]))
        return (0);//regarde si lespace alloue est egale a 0, 16 car ya 16 ints
    i = -1;
    j = 0;
    while (av[1][++i])//tant que le 2nd parametre nest pas fini
    {
        if (av[1][i] >= '0' && '9' >= av[1][i])
            entrees[i] = av[1][i] - '0';//conversion de chque char en int via atoi
    }
    check (0, *possibility, entrees);
    return (0);
}