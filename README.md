SISOP-TP02-VirtualMemory


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

2- Conforme o tamanho das páginas cresce?
Cresce em ordem crescente, litle endian.

3- Por que não se deve utilizar tabelas grandes demais?

