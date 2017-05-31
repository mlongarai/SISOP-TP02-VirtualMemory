SISOP-TP02-VirtualMemory

Exercicio: https://github.com/mlongarai/SISOP-TP02-VirtualMemory/blob/master/TP2-2.pdf

1)
VA (bits)	Page size (kilobytes)	PTE size (bits)	VPN (bits)	Offset (bits)	TAM (bytes)
32			8k						8				2ˆ19		2ˆ13			4194304
32			4k						8				2ˆ20		2ˆ12			8388608
32			8k						4				2ˆ19		2ˆ13			2097152
32			2k						4				2ˆ21		2ˆ11			8388608

2)
python paging-linear-translate.py -P 1k -a 1m -p 512m -v -n 0
python paging-linear-translate.py -P 1k -a 2m -p 512m -v -n 0
python paging-linear-translate.py -P 1k -a 4m -p 512m -v -n 0

paging-linear-translate.py -P 1k -a 1m -p 512m -v -n 0
paging-linear-translate.py -P 2k -a 1m -p 512m -v -n 0
paging-linear-translate.py -P 4k -a 1m -p 512m -v -n 0

print 'ARG seed',               options.seed -s 	// Endereço randomico
print 'ARG address space size', options.asize -a 	// Espaco de enderecamento
print 'ARG phys mem size',      options.psize -p 	// Espaco fisico
print 'ARG page size',          options.pagesize -P // Tamanho da pagina
print 'ARG verbose',            options.verbose -v  // Verbose
print 'ARG addresses',          options.addresses -A// Endereço

1- Como o tamanho das tabelas de páginas deve mudar conforme o espaço de endereçamento virtual cresce?

O tamanho da tabela de paginas varia de acordo com o tamanho do espaco de enderecamento. Se aumentar o space size, aumenta o tamanho da tabela. Logo, se eu quiser diminuir a tabela, ou aumenta o page size ou diminui o space size.

2- Conforme o tamanho das páginas cresce?
Conforme o space size aumenta, a page size diminui.

3- Por que não se deve utilizar tabelas grandes demais?
Porque voce estará colocando uma tabela muito grande dentro da memória. Exemplo: Conforme o tamanho do espaco de enderecamento, maior é numero de paginas alocadas na memoria. O calculo para saber a quantidade de paginas armazenadas é = VA/PageSize = Numero de paginas e para saber o quanto ocupa é o NumeroDePaginas * PTE Size.

