/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frankenmain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 00:39:53 by lde-medi          #+#    #+#             */
/*   Updated: 2024/11/26 02:06:07 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

/* al final las estructuras se han quedado practicamente tales y como las habia planeado,
en map_data ponemos todos los datos que validamos de la primera linea del mapa, en
map_data.grid el puntero a la matriz que vamos a llenar con el mapa.
le sub-estructura bsq almacena los datos del cuadrado mas grande que hayamos encontrado */

typedef struct s_biggest_square
{
	int	line;
	int	column;
	int	size;
}	t_bsq;

typedef struct s_map_data
{
	int		lines_n;
	int		cols_n;
	char	empty_char;
	char	obst_char;
	char	full_char;
	char	*grid;
	t_bsq	bsq;
}	t_map_d;

/*  aqui iran todos los prototipos de momento pero soloo los de funciones que hayan sido completadas
(aunque sean completas, usando funciones que todavia no existen lo se no tiene mucho sentido pero
en verdad si lo tiene.) */

int		process_map(char	*file_name);
int		read_file(char	*file_name, char	**buffer);
ssize_t	get_file_size(char	*file_name);
size_t	grid_arr_len(char	*buffer, t_map_d *map_data, int i);
int		parse_input(char	*buffer, t_map_d	*map_data);
int		validate_first_line(char *buffer, t_map_d *map_data, int *i);
int		first_line_len(char	*buffer);
int		validate_grid(char	*buffer, t_map_d	*map_data, int	*i);
int		lines_validation(char	*buffer, int i, t_map_d	*map_data);
void	fill_grid(char	*buffer, t_map_d	*map_data, int i, int len);
int		is_valid_char(t_map_d	*map_data, char c);
int		is_digit(char c);
int		is_printable(char c);
void	init_struct(t_map_d *map_data);
void	print_grid(t_map_d *map_data);


int	main(int argc, char *argv[])
{
	int	i;

/*   empezamos desde el 1 para no intentar leer como nombre de file el nombre del programa
    y si hay solo un argumento escribimos en pantalla las instrucciones de como hay que
    usar el programa, (un poco como hacia el mismo generador de mapas perl que nos dieron) */

	i = 1;
	if (argc < 2)
	{
		write(2, "Launch program with n arguments (map files names.)\n", 51);
		return (1);
	}

/*   si tenemos argumentos, los intentamos enviar a la funcion process map suponendo que sean
    el nombre de los file .map que vamos a intentar procesar, process_map devuelve 1 cuando 
    ha podido hacer su trabajo correctamente, 0 cuando hay cualquier tipo de error (ex. problemas
    leyendo el file o de validacion de los mapas) */

	while (i < argc)
	{
		if (!process_map(argv[i]))
		{
			write(2, "map error\n", 10);
			return (1);
		}
		if (i != argc - 1)
			write(1, "\n", 1);
		i++;
	}
	return (0);
}

int	process_map(char	*file_name)
{
	char	*buffer;
	t_map_d	map_data;

	buffer = NULL;
	init_struct(&map_data); // <- funcion para crear, ahora no me apetece | lorenzo del pasado es un perro, ya lo hice

/*     en la siguiente condicion retornamos 0 (que en el main mandaria el map error) siempre
    y cuando read_file retorne 0 o cuando retorne 0 parse_input (osea, si ha habido problemas
    a la hora de leer el file o el mapa no era valido, retornamos a la condicion del main de
    map error, si ambas operaciones van bien, seguimos con el programa) read_file usa un puntero
    al buffer porque tiene que modificarlo, en parse input lo pasamos como variable, porque solo
    tiene que leer los valores sin necesariamente modificarlos, mientras de la estructura si pasamos
    un puntero porque en parse_input pasaremos los valores como caracteres validos del mapa etc. */

	if (!read_file(file_name, &buffer) || !parse_input(buffer, &map_data))
		return (0);

/*   una vez almacenados todos los datos del file map al struct map_data, no necesitamos mas
    el buffer (el megastring donde almacenamos todo el file de una) asi que lo libramos como
    adultos responsables */

	free(buffer);

/*     aqui intentaremos todas las celdas una a una por el cuadrado mas grande, fuerza bruta y
    deberiamos tener la solucion si o si, he oido fuera del campus fumando nacho hablar de 
    su idea para optimizar esto, no probar nunca un cuadrado mas chico del mas grande que
    hemos encontrado hasta ahora, y la verdad es que me quito la gorra, de repente nuestro
    algoritmo va a funcionar no se que magnitud de n mas rapido solo por esto, peeeero...
    antes lo hare' como yo se, vamos con un producto funcional lo primero, luego si hay tiempo
    se optimiza */

	//try_all_cells(&map_data); // <- function para crear
	//write_to_grid(&map_data); // <- funcion para crear, se me habia olvidado en el plan inicial.
	print_grid(&map_data); // <- funcion para crear, easy 	queria verlo funcionar, la cree de prisa y corriendo

/*     otra vez, los adultos responsables liberan la memoria cuando han terminado de trabajar
    con ella, si ya hemos impreso en pantalla la grid con la solucion es la hora de librar
    la memoria de esta inutil grid que nos queda por las manos */

	free(map_data.grid);
	return (1);
}

// se explica sola, 0 a todo. siempre. 0. 0. 0...

void	init_struct(t_map_d *map_data)
{
	map_data->lines_n = 0;
	map_data->cols_n = 0;
	map_data->empty_char = '\0';
	map_data->obst_char = '\0';
	map_data->full_char = '\0';
	map_data->grid = NULL;
	map_data->bsq.line = 0;
	map_data->bsq.column = 0;
	map_data->bsq.size = 0;
}

/*  al final he rehecho read-file de 0, no porque estuviera mal, pero sin acceso al repo de 42 no la
tenia, y la necesitaba para testear el parsing, lo mismo el get_file_size. */

int	read_file(char	*file_name, char	**buffer)
{
	int		file;
	ssize_t	file_size;
	ssize_t	bytes_read;

	file = 0;

/*     antes de hacer malloc, tengo que saber cuanto es de grande el mapa que estoy leyendo, y luego
    le doy +1 para tener un caracter nulo al final. */

	file_size = get_file_size(file_name);
	*buffer = malloc((file_size + 1) * sizeof(char));

    // si el malloc falla, return 0, osea error. (acabara' como todos en map error.)

	if (!*buffer)
		return (0);

/*       si malloc no ha tenido problemas, abrimos el file. (por cierto, intente'
     un malloc imposible tipo 16gb, retorna un NULL pointer, aburrido, esperaba 
     por lo menos olor a quemado de la ram.) */

	file = open(file_name, O_RDONLY);

/*     si hemos tenido problemas en abrir el file (podriamos estar intentando abrir test_map cuando el
    archivo es test.map por ejemplo o podriamos simplemente tener un error de lectura) libramos el 
    buffer que acabamos de preparar, poque no va a haber file para rellenarlo, y luego retornamos 0
    (el mismito map error al que acabamos siempre que tenemos un 0 en esta funcion) */

	if (file < 0)
	{
		free(*buffer);
		return (0);
	}

/*     finalmente leemos el file, hasta el final porque conocemos su tamano, y lo almacenamos en buffer
    que terminamos responsablemente con un '\0'. */

	bytes_read = read(file, *buffer, file_size);
	(*buffer)[file_size] = '\0';

/*     si hemos leido menos bytes que el tamano del file, sabemos que en esta lectura algo ha ido mal
    y lo mismo de siempre, damos error, pero visto que habiamos alocado un buffer, lo libramos de 
    forma responsable. */

	if (bytes_read != file_size)
	{
		free(*buffer);
		return (0);
	}

    // si hemos llegado hasta aqui es que todo ha ido bien, y devolvemos el 1

	return (1);
}

ssize_t	get_file_size(char	*file_name)
{
	int		file;
	ssize_t	size;
	char	buf;

	size = 0;
	file = open(file_name, O_RDONLY);
	if (file < 0)
		return (0);

 // 0 en read es EOF (end of file), 1 = leido, -1 error. 
    
	while (read(file, &buf, 1) == 1)
		size++;
	close(file);
	return (size);
}

int	parse_input(char	*buffer, t_map_d	*map_data)
{
	int		i;
    
/*     se explica bastante bien sola, solo es una funcion contenedor para los dos controles de validacion
    y a la vez de validar va moviendo los valores al struct apuntado por map_data */

	i = 0;
	if (!validate_first_line(buffer, map_data, &i))
		return (0);
	else if (!validate_grid(buffer, map_data, &i))
		return (0);
	else
		return (1);
}

int	validate_first_line(char *buffer, t_map_d *map_data, int *i)
{
	int	len;

/* 	calculo cuanto de larga es la primera linea, y cuento
	los digitos solo hasta el tamano menos 3 (numero de 
	caracteres o digitos que seran usados para dibujar el mapa)
	el resto de esta linea es el numero de lineas en el */

	len = first_line_len(buffer);
	map_data->lines_n = 0;

/* 	este monstruo de bucle es un filtro, que retorna errores en casos
	muy especificos, como se que el numero de las lineas es todo lo que
	no es los ultimos 3 caracteres de la linea, pongo de primeras esta condicion
	para atrapar todos los digitos de las lineas, y luego en orden simplemente
	miro si todavia no tengo un char por el vacio, tiene que ir alli, luego el segundo
	y asi relleno la estructura con los datos de la primera linea. */

	while (buffer[*i])
	{
		if ((map_data->lines_n == 0 && !is_digit(buffer[*i])))
			return (0);
		if (is_digit(buffer[*i]) && *i < len - 3)
			map_data->lines_n = (map_data->lines_n * 10) + (buffer[*i] - '0');
		else if (is_printable(buffer[*i]) && map_data->empty_char == '\0')
			map_data->empty_char = buffer[*i];
		else if (is_printable(buffer[*i]) && map_data->obst_char == '\0')
			map_data->obst_char = buffer[*i];
		else if (is_printable(buffer[*i]) && map_data->full_char == '\0')
			map_data->full_char = buffer[*i];
		else if (buffer[*i] == '\n')
		{
			return (++(*i), 1);
		}
		else
			return (0);
		(*i)++;
	}
	return (0);
}

/* tengo que saber cuanto es de larga la primera linea, asi que hago un
strlen pero solo hasta el primer salto de linea. */


int	first_line_len(char	*buffer)
{
	int	len;

	len = 0;
	while (buffer[len])
	{
		if (buffer[len] == '\n')
			break ;
		len++;
	}
	return (len);
}

int	validate_grid(char	*buffer, t_map_d	*map_data, int	*i)
{
	size_t	len;

/* 	primero pasamos una funcion para asegurarnos de que todas las lineas del 
	mapa tengan la misma length y solo caracteres legales */

	if (!lines_validation(buffer, *i, map_data))
		return (0);

/* 	funciona como get_file_size, solo es un glorificado strlen,
	para hacer luego malloc del tamano de la grid.
	y si el tamano de nuestra grid es de 0, sinifica que no hay 
	una celda de 1x1 y el mapa es invalido. */

	len = grid_arr_len(buffer, map_data, *i);
	if (!len)
		return (0);

	// si hay mapa, malloc del tamano del mapa + 1 del null char
	
	map_data->grid = malloc((len * sizeof(char)) + 1);

/* 	rellena la grid que acabamos de alocar con la grid que hemos validado
	mas arriba. */

	fill_grid(buffer, map_data, *i, (int)len);
	return (1);
}

int	lines_validation(char	*buffer, int i, t_map_d	*map_data)
{
	int	ln_skips;
	int	curr_len;
	
/* 	contamos los saltos de lineas porque queremos comprobar que tiene la cantidad de lineas que decia en la 
	leyenda (desde ahora siempre voy a llamar la primera linea de un mapa su leyenda.) y despues de haber contado
	las columnas de la primera linea, lo almacenamos en nuestra estructura, y luego anadimos una condicion que 
	asegura que al final de una linea, si esta ultima linea que estoy midiendo es diferente de la anterior, el mapa
	es invalido */

	ln_skips = 0;
	curr_len = 0;
	while (buffer[i])
	{
		if (buffer[i++] == '\n')
		{
			if (!ln_skips++)
				map_data->cols_n = curr_len;
			else if (curr_len != map_data->cols_n)
				return (0);
			curr_len = 0;
		}
		else
			curr_len++;
	}
	if (ln_skips != map_data->lines_n)
		return (0);
	else
		return (1);
}

void	fill_grid(char	*buffer, t_map_d	*map_data, int i, int len)
{
	// copia el mapa a la grid que hemos alocado poco antes aqui fuera.
	int	j;

	j = 0;
	while (buffer[i] && j < len)
	{
		if (buffer[i] == '\n')
			i++;
		else
		{
			map_data->grid[j] = buffer[i];
			j++;
			i++;
		}
	}
	map_data->grid[j] = '\0';
}

// calculo cuanto de largo es el mapa, quitando los saltos de linea

size_t	grid_arr_len(char	*buffer, t_map_d *map_data, int i)
{
	size_t	len;

	len = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			i++;
		else if (is_valid_char(map_data, buffer[i]))
		{
			len++;
			i++;
		}
		else
			return (0);
	}
	return (len);
}

void	print_grid(t_map_d *map_data)
{
	int	i;

	i = 0;
	while (map_data->grid[i])
	{
		if (i % map_data->cols_n == 0 && i != 0)
			write(1, "\n", 1);
		write(1, &map_data->grid[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

// bools que se explican solas.

int	is_valid_char(t_map_d	*map_data, char c)
{
	return (c == map_data->empty_char || c == map_data->full_char
		|| c == map_data->obst_char);
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_printable(char c)
{
	return ((unsigned char)c >= 33 && (unsigned char)c <= 127);
}
