#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);
void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);

/**
 * Check_ELF: ELF FILE TO BE Checked
 * @e_Dent: Pointers THat have ARRAY Numbers
 * Destription: NOT ELF file, EXIT 88
 */
void check_elf(unsigned char *e_ident)
{
        int index;
        for (index = 0; index < 4; index++)
        {
                  if (e_ident[index] != 127 &&
                                  e_ident[index] != 'E' &&
                                    e_ident[index] != 'L' &&
                                    e_ident[index] != 'F')
                  {
                          dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
                       exit(98);
                  }
        }
}


/**
 * PRINT_Maghic: MAgic gto be Printed By ELF header File.
 * @e_Ident: ARRAY Containg NUMBERS.
 * Description: Magic Numbers To be separated BY Letters,
 */
void print_magic(unsigned char *e_ident)
{
	int index;

	printf(" Magic: ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", e_ident[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");

	}
}

/**
 * PRINT_CLASS - PRINTED class of an ELF Header.
 * @E_IDent: THE Pointer OF THE Array containing the ELF Class.
 */
void print_class(unsigned char *e_ident)
{
	printf(" Class: ");

	switch (e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;

		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * PRINT_DATA - Printed  DATA of THE ELF Header.
 *    @E_Ident:  PointerS to THE Array ThAT HAs ELF class.
 */
void print_data(unsigned char *e_ident)
{
	printf(" Data: ");

	switch (e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);

	}
}

/**
 * print_version - The Version of THE ELF Header HAS BEEN Printed.
 * @E_Ident: A pointer to The array THAT Has An ELF version.
 */
void print_version(unsigned char *e_ident)
{
	printf(" Version: %d",
			 e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
			break;
	}
}

/**
 *  PRINT_OSABI - Printend  OSA|BI of The ELF header.
 *  @E_Ident: Pointers Of an array That Has The EL/F version.
 */
void print_osabi(unsigned char *e_ident)
{
	printf(" OS/ABI: ");


	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * Print_ABI - Printed  ABI Version of THE ELF HeadeR.
 *  @E_Ident: THE Pointer Of The Array containing  ELF AB|I versioN.
 */
void print_abi(unsigned char *e_ident)
{
	printf(" ABI Version: %d\n",
			e_ident[EI_ABIVERSION]);
}

/** 
 * PRINT_TYPE - PrintEd  Type of The ELF Header.
 * @E_Type: ELF Header Has A Type.
 *     @E_Ident: THE Pointer Of The Array Has ELF Class.
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;
	printf(" Type: ");

	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", e_type);
	}
}

/**
 * Print_Entry - Entry Point of The ELF Header Printed.
 * @E_Entry:  Address of An ELF entry point Found,
 * @E_Ident: The Pointer to The  Array Has  ELF class.
 */
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf(" Entry point address: ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			 ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}
	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);
	else
		printf("%#lx\n", e_entry);
}

/**
 * Close_ALF - ELF file Has To be Closed.
 *     @Elf: FILE Descriptor of An ELF file.
 *      Description: TO CLOSE THE FILE - exit code 88.
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * Main - Displays the information On The Main File.
 * @Argc: Arguments supplied on to The Program.
 * @Argv: ARG Array of pointerS.
 * Return: Alway 0 on Success
 * Description: ELF FILE SUCCESS, exit 88
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n",
argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n",
argv[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n",
argv[1]);
		exit(98);
	}


	print_entry(header->e_entry, header->e_ident);
	check_elf(header->e_ident);
	printf("ELF Header:\n");
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident);
	print_abi(header->e_ident);
	print_type(header->e_type, header->e_ident);

	free(header);
	close_elf(o);
	return (0);
}


















