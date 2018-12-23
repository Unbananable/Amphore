/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtrigalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 19:53:07 by dtrigalo          #+#    #+#             */
/*   Updated: 2018/12/23 18:50:55 by dtrigalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	ft_printf("\nft_printf: %d\n", 42);
	printf("   printf: %d\n", 42);

	ft_printf("\nft_printf: %-5d\n", 42);
	printf("   printf: %-5d\n", 42);

	ft_printf("\nft_printf: %+d\n", -42);
	printf("   printf: %+d\n", -42);

	ft_printf("\nft_printf: %-505.d\n", 42);
	printf("   printf: %-505.d\n", 42);

	ft_printf("\nft_printf: %ld\n", 12345678901);
	printf("   printf: %ld\n", 12345678901);

	ft_printf("\nft_printf: %-5ld\n", 12345678901);
	printf("   printf: %-5ld\n", 12345678901);

	ft_printf("\nft_printf: %+ld\n", -12345678901);
	printf("   printf: %+ld\n", -12345678901);

	ft_printf("\nft_printf: %-505.ld\n", 12345678901);
	printf("   printf: %-505.ld\n", 12345678901);

	ft_printf("\nft_printf: %lld\n", 12345678901);
	printf("   printf: %lld\n", 12345678901);

	ft_printf("\nft_printf: %-5lld\n", 12345678901);
	printf("   printf: %-5lld\n", 12345678901);

	ft_printf("\nft_printf: %+lld\n", -12345678901);
	printf("   printf: %+lld\n", -12345678901);

	ft_printf("\nft_printf: %-505.lld\n", 12345678901);
	printf("   printf: %-505.lld\n", 12345678901);

	ft_printf("\nft_printf: %o\n", 42);
	printf("   printf: %o\n", 42);

	ft_printf("\nft_printf: %-5o\n", 42);
	printf("   printf: %-5o\n", 42);

	ft_printf("\nft_printf: %+o\n", -42);
	printf("   printf: %+o\n", -42);

	ft_printf("\nft_printf: %-505.o\n", 42);
	printf("   printf: %-505.o\n", 42);

	ft_printf("\nft_printf: %x\n", 42);
	printf("   printf: %x\n", 42);

	ft_printf("\nft_printf: %-5x\n", 42);
	printf("   printf: %-5x\n", 42);

	ft_printf("\nft_printf: %+x\n", -42);
	printf("   printf: %+x\n", -42);

	ft_printf("\nft_printf: %-505.x\n", 42);
	printf("   printf: %-505.x\n", 42);

	ft_printf("\nft_printf: %f\n", 42.42);
	printf("   printf: %f\n", 42.42);

	ft_printf("\nft_printf: %-5f\n", 42.42);
	printf("   printf: %-5f\n", 42.42);

	ft_printf("\nft_printf: %+f\n", -42.42);
	printf("   printf: %+f\n", -42.42);

	ft_printf("\nft_printf: %-505.f\n", 42.42);
	printf("   printf: %-505.f\n", 42.42);

	ft_printf("\nft_printf: %s\n", "J'aime j'aime GEMO");
	printf("   printf: %s\n", "J'aime j'aime GEMO");

	ft_printf("\nft_printf: %% Testons %% son %% efficacité %%\n");
	printf("   printf: %% Testons %% son %% efficacité %%\n");

	ft_printf("\nft_printf: %c\n", 'a');
	printf("   printf: %c\n", 'a');

	ft_printf("\nft_printf: %c\n");
	printf("   printf: %c\n (%%c with no arguments)");

	ft_printf("\nft_printf: %c\n", 'a', 'b');
	printf("   printf: %c\n", 'a', 'b');

	ft_printf("\nft_printf: %c et %c\n", 'a');
	printf("   printf: %c et %c\n", 'a');

	ft_printf("\nft_printf: %llhhd\n", 42);
	printf("   printf: %llhhd\n", 42);

	ft_printf("\nft_printf: %llf\n", 12345678901.42);
	printf("   printf: %llf\n", 12345678901.42);

	ft_printf("\nft_printf: %-5zf\n", 42.42);
	printf("   printf: %-5zf\n", 42.42);

	ft_printf("\nft_printf: %-zd\n", 42);
	printf("   printf: %-zd\n", 42);

	ft_printf("\nft_printf: %jd\n", -12345678901);
	printf("   printf: %jd\n", -12345678901);

	ft_printf("\nft_printf: %d\n", -123 % 10);
	printf("   printf: %d\n", -123 % 10);

	ft_printf("\nft_printf: %jd\n", 3);
	printf("   printf: %jd\n", 3);

	ft_printf("\nft_printf: %jd\n", -42);
	printf("   printf: %jd\n", -42);

	ft_printf("\nft_printf: %jd\n", 42);
	printf("   printf: %jd\n", 42);

	ft_printf("\nft_printf: %jd\n", 0);
	printf("   printf: %jd\n", 0);

	ft_printf("\nft_printf: %jd\n");
	printf("   printf: %jd DIFFERENT IS OKAY !\n");

	ft_printf("\nft_printf: %8.58d\n", -1092893216);
	printf("   printf: %8.58d\n", -1092893216);

	ft_printf("\nft_printf: %i\n", 42);
	printf("   printf: %i\n", 42);

	ft_printf("\nft_printf: %-5i\n", 42);
	printf("   printf: %-5i\n", 42);

	ft_printf("\nft_printf: %+i\n", -42);
	printf("   printf: %+i\n", -42);

	ft_printf("\nft_printf: %-505.i\n", 42);
	printf("   printf: %-505.i\n", 42);

	ft_printf("\nft_printf: %li\n", 12345678901);
	printf("   printf: %li\n", 12345678901);

	ft_printf("\nft_printf: %-5li\n", 12345678901);
	printf("   printf: %-5li\n", 12345678901);

	ft_printf("\nft_printf: %+li\n", -12345678901);
	printf("   printf: %+li\n", -12345678901);

	ft_printf("\nft_printf: %-505.li\n", 12345678901);
	printf("   printf: %-505.li\n", 12345678901);

	ft_printf("\nft_printf: %lli\n", 12345678901);
	printf("   printf: %lli\n", 12345678901);

	ft_printf("\nft_printf: %-5lli\n", 12345678901);
	printf("   printf: %-5lli\n", 12345678901);

	ft_printf("\nft_printf: %+lli\n", -12345678901);
	printf("   printf: %+lli\n", -12345678901);

	ft_printf("\nft_printf: %-505.lli\n", 12345678901);
	printf("   printf: %-505.lli\n", 12345678901);

	ft_printf("\nft_printf: %10.2hi\n", 0);
	printf("   printf: %10.2hi\n", 0);

	ft_printf("\nft_printf: %10.3i\n", 5);
	printf("   printf: %10.3i\n", 5);

	ft_printf("\n(ft_printf) test: % -2hi\n", 424242);
	printf("            test: % -2hi\n", 424242);

	ft_printf("\n(ft_printf) test: %0+42.2ji\n", 12345678901);
	printf("   printf   test: %0+42.2ji\n", 12345678901);

	ft_printf("\n(ft_printf) test: %+60i\n", 678901);
	printf("   printf   test: %+60i\n", 678901);

	ft_printf("\n(ft_printf) test: % 040i\n", 678901);
	printf("   printf   test: % 040i\n", 678901);

	ft_printf("\n(ft_printf) test: % -60i\n", -678901);
	printf("   printf   test: % -60i\n", -678901);

	ft_printf("\n(ft_printf) test: %02i\n", 0);
	printf("   printf   test: %02i\n", 0);

	ft_printf("\n(ft_printf) test: % -2.10i\n", -123456);
	printf("   printf   test: % -2.10i\n", -123456);

	ft_printf("\n(ft_printf) test: % -2.15i\n", 0);
	printf("   printf   test: % -2.15i\n", 0);

	ft_printf("\n(ft_printf) test: %#o\n", 0);
	printf("   printf   test: %#o\n", 0);

	ft_printf("\n(ft_printf) test: %.01s__end\n", "");
	printf("   printf   test: %.01s__end\n", "");

	ft_printf("\n(ft_printf) test: %#X\n", 0);
	printf("   printf   test: %#X\n", 0);

	ft_printf("\n(ft_printf) test: %#x\n", 0);
	printf("   printf   test: %#x\n", 0);

	ft_printf("\n(ft_printf) test: %#o\n", 0);
	printf("   printf   test: %#o\n", 0);

	ft_printf("\n(ft_printf) test: % 0+-#10.5llX\n", 42);
	printf("   printf   test: % 0+-#10.5llX\n", 42);

	ft_printf("\n(ft_printf) test: % 0+-#10.5llx\n", 42);
	printf("   printf   test: % 0+-#10.5llx\n", 42);

	ft_printf("\n(ft_printf) test: % 0+-#10.5llo\n", 4020);
	printf("   printf   test: % 0+-#10.5llo\n", 4020);

	ft_printf("\n(ft_printf) test: %#04x\n", 424242);
	printf("   printf   test: %#04x\n", 424242);

	ft_printf("\n(ft_printf) test: %+-0#2x\n", 0);
	printf("   printf   test: %+-0##2x\n", 0);

	ft_printf("\n(ft_printf) test: % c__end\n", '\0');
	printf("   printf   test: % c__end\n", '\0');

	ft_printf("\n(ft_printf) test: %#.d__end\n", 0);
	printf("   printf   test: %#.d__end\n", 0);

	ft_printf("\n(ft_printf) test: %1s__end\n", "");
	printf("   printf   test: %1s__end\n", "");

	ft_printf("\n(ft_printf) test: %.d__end\n", 0);
	printf("   printf   test: %.d__end\n", 0);

	ft_printf("\n(ft_printf) test: %01.x__end\n", 0);
	printf("   printf   test: %01.u__end\n", 0);

	ft_printf("\n(ft_printf) test: %01.X__end\n", 0);
	printf("   printf   test: %01.u__end\n", 0);

	ft_printf("\n(ft_printf) test: %01.o__end\n", 0);
	printf("   printf   test: %01.o__end\n", 0);

	ft_printf("\n(ft_printf) test: %01s__end\n", "");
	printf("   printf   test: %01s__end\n", "");

	ft_printf("\n(ft_printf) test: %.o__end\n", 0);
	printf("   printf   test: %.o__end\n", 0);

	ft_printf("\n(ft_printf) test: %01.u__end\n", 0);
	printf("   printf   test: %01.u__end\n", 0);

	ft_printf("\n(ft_printf) test: %.u__end\n", 0);
	printf("   printf   test: %.u__end\n", 0);

	ft_printf("\n(ft_printf) test: %.d__end\n", 0);
	printf("   printf   test: %.d__end\n", 0);

	ft_printf("\n(ft_printf) test: %.2p__end\n", 0);
	printf("   printf   test: %.2p__end\n", 0);

	ft_printf("\n(ft_printf) test: %s__end\n", "this is a string");
	printf("   printf   test: %s__end\n", "this is a string");

	ft_printf("\n(ft_printf) test: %.x__end\n", 0);
	printf("   printf   test: %.x__end\n", 0);

	ft_printf("\n(ft_printf) test: %#.0x__end\n", 0);
	printf("   printf   test: %#.0x__end\n", 0);
	printf(" \n  printf: FIN\n");

	return (42);
}
