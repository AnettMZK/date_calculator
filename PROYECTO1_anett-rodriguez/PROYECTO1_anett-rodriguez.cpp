
#include <iostream>
#include <stdlib.h>

void menu() {
	std::cout << "\n..........................................\n";
	std::cout << "                     MENU                   \n";
	std::cout << "   [1] Formato dd/mm/yyyy.                  \n";
	std::cout << "   [2] Comparacion de fechas.               \n";
	std::cout << "   [3] Diferencia de fechas.                \n";
	std::cout << "   [4] Suma de fechas.                      \n";
	std::cout << "   [5] Resta de fechas.                     \n";
	std::cout << "   [6] Cuanto tiempo ha pasado?             \n";
	std::cout << "   [7] Fechas en formato largo.             \n";
	std::cout << "   [8] Salir.                               \n";
	std::cout << "..........................................\n";
}

int formatYear(int year) {
	if (year < 100) {
		year += 2000; 
	}
	return year; 
}

void formatDate(int day, int month, int year) {
	if (day < 10) {
		std::cout << "0";
	} std::cout << day << "/";

	if (month < 10) {
		std::cout << "0";
	} std::cout << month << "/";

	if (year < 100) {
		year += 2000;
	}std::cout << year << std::endl;

}

void compareDate(int day1, int day2, int month1, int month2, int year1, int year2) {
	if ((formatYear(year1) == formatYear(year2)) && (month1 == month2) && (day1 == day2)) {
		std::cout << "Las fechas son iguales" << std::endl;
	}
	else {
		if (formatYear(year1) > formatYear(year2)) {
			formatDate(day1, month1, year1);
			std::cout << "La primera fecha es mayor\n";
		} 
		else if (formatYear(year1) < formatYear(year2)) {
			formatDate(day2, month2, year2);
			std::cout << "La segunda fecha es mayor\n";
		}
		else {
			if (month1 > month2) {
				formatDate(day1, month1, year1);
				std::cout << "La primera fecha es mayor\n";
			}
			else if (month1 < month2) {
				formatDate(day2, month2, year2);
				std::cout << "La segunda fecha es mayor\n";
			}
		else {
			if (day1 > day2) {
				formatDate(day1, month1, year1);
				std::cout << "La primera fecha es mayor\n";
			}
			else if (day1 < day2) {
				formatDate(day2, month2, year2);
				std::cout << "La segunda fecha es mayor\n";
				}
			}
		}
	}
}

bool leapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}

int conditionOfDays(int month, int year) {
	int numberDay = 31; 
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		numberDay = 30; 
	}
	else if (month == 2) {
		if (leapYear(year)) {
			numberDay = 29; 
		}
		else {
			numberDay = 28; 
		}
	}
	return numberDay; 
}

int Hours(int quantityDays) {
	quantityDays *= 24;
	return quantityDays;
}

void setNewDates(int day1, int month1, int year1, int day2, int month2, int year2, int& maxDay, int& maxMonth, int& maxYear) {

	if (formatYear(year1) == formatYear(year2)) {
		if (month1 == month2) {
			if (day1 == day2) {
				std::cout << "Las fechas son iguales" << std::endl;
			}
			else {
				if (day1 < day2) {
					maxDay = day2;
					maxMonth = month2;
					maxYear = formatYear(year2);
				}
				else {
					maxDay = day1;
					maxMonth = month1;
					maxYear = formatYear(year1);
				}
			}
		}
		else {
			if (month1 < month2) {
				maxDay = day2;
				maxMonth = month2;
				maxYear = formatYear(year2);
			}
			else {
				maxDay = day1;
				maxMonth = month1;
				maxYear = formatYear(year1);
			}
		}
	}
	else {
		if (formatYear(year1) < formatYear(year2)) {
			maxDay = day2;
			maxMonth = month2;
			maxYear = formatYear(year2);
		}
		else {
			maxDay = day1;
			maxMonth = month1;
			maxYear = formatYear(year1);
		}
	}
}

void dateDifference(int day1, int day2, int month1, int month2, int year1, int year2) {
	int quantityDays = 0;  int quantityMonths = 0;
	int minorDay, minorMonth, minorYear; 
	int majorDay, majorMonth, majorYear; 
	int maxDays = 0;

	setNewDates(day1, month1, year1, day2, month2, year2, majorDay, majorMonth, majorYear);

	if (majorDay == day1 && majorMonth == month1 && majorYear == formatYear(year1)) {
		minorDay = day2;
		minorMonth = month2;
		minorYear = formatYear(year2);
	}
	else {
		minorDay = day1;
		minorMonth = month1;
		minorYear = formatYear(year1);
	}

	while (minorDay != majorDay || minorMonth != majorMonth || minorYear != majorYear) {
		maxDays = conditionOfDays(minorMonth, minorYear);
		if (minorDay < maxDays) {
			minorDay++;
			quantityDays++;
		}
		else {
			minorDay = 1;
			quantityDays++;
			if (minorMonth + 1 > 12) {
				minorMonth = 1;
				minorYear++;
			}
			else {
				minorMonth++;
			}
			if (minorMonth != month1) {
				quantityMonths++;
			}
		}
	}

	std::cout << "La diferencia de dias es: " << quantityDays << std::endl;
	std::cout << "La diferencia de meses es: " << quantityMonths << std::endl;
	std::cout << "La diferencia en horas es: " << Hours(quantityDays) << std::endl;
}

void plusDays(int day, int month, int year, int plus) {
	for (int i = 0; i < plus; i++) {
		day++; 

		if (day > conditionOfDays(month, year)) {
			day = 1; 
			month++;
		}
		if (month > 12) {
			month = 1; 
			year++;
		}
	}
	formatDate(day, month, year); 
}

void minusDays(int day, int month, int year, int minus) {
	for (int i = 0; i < minus; i++) {
		day--; 
		if (day < 1) {
			month--;
			if (month < 1) {
				month = 12;
				year--; 
			}
			day = conditionOfDays(month, year); 
		}
	}
	formatDate(day, month, year); 
}

int dateDistance(int year1, int year2) {
	int distance; 

	if (year1 > year2) {
		distance = formatYear(year1) - formatYear(year2);
	}
	else {
		distance = formatYear(year2) - formatYear(year1);
	}
	return distance; 
}

void ifLeapYear(int year1, int year2) {
	if (leapYear(year1)) {
		std::cout << "El anio " << formatYear(year1) << " es bisiesto\n";
	}
	else {
		std::cout << "El anio " << formatYear(year1) << " no es bisiesto\n";
	}

	if (leapYear(year2)) {
		std::cout << "El anio " << formatYear(year2) << " es bisiesto\n";
	}
	else {
		std::cout << "El anio " << formatYear(year2) << " no es bisiesto\n";
	}
}

std::string longFormat(int month) {
	switch (month) {
	case 1: return "enero"; 
	case 2: return "febrero";
	case 3: return "marzo";
	case 4: return "abril";
	case 5: return "mayo";
	case 6: return "junio";
	case 7: return "julio";
	case 8: return "agosto";
	case 9: return "septiembre";
	case 10: return "octubre";
	case 11: return "noviembre";
	case 12: return "diciembre";

	default: 
		return "";	
	}
}

int main()
{
	int option = 0, distance = 0, plus = 0, minus = 0; 
	int day1 = 0, month1 = 0, year1 = 0;
	int day2 = 0, month2 = 0, year2 = 0;

	do {
		std::cout << "......................\n";
		std::cout << "  Ingrese dos fechas. \n";
		std::cout << ".......................\n";

		std::cout << "Ingrese la primera fecha: ";
		std::cin >> day1 >> month1 >> year1;

		std::cout << "Ingrese la segunda fecha: ";
		std::cin >> day2 >> month2 >> year2;

		if (day1 > 31 || day2 > 31) {
			std::cout << "\nFORMATO DE FECHA INVALIDO.\n";
		}
		else if (month1 > 12 || month2 > 12) {
			std::cout << "\nFORMATO DE FECHA INVALIDO.\n";
		}
		else if (year1 > 3000 || year2 > 3000) {
			std::cout << "\nFORMATO DE FECHA INVALIDO.\n";
		}

	} while ((day1 > 31 || day2 > 31) && (month1 > 12 || month2 > 12) && (year1 > 3000 || year2 > 3000));

	do {
		menu(); 

		std::cout << "Ingrese una opcion: "; 
		std::cin >> option; 

		system("cls"); 

		switch (option) {
		case 1:
			std::cout << "  EL FORMATO DE FECHA ES: \n"; 
			std::cout << "--------------------------\n";

			std::cout << "La primera fecha: "; formatDate(day1, month1, year1);
			std::cout << "La segunda fecha: "; formatDate(day2, month2, year2);

			break; 
		case 2:
			std::cout << "  EL RESULTADO DE LA COMPARACION ES:  \n";
			std::cout << "--------------------------------------\n";

			compareDate(day1, day2, month1, month2, year1, year2); 

			break;
		case 3:
			std::cout << "  LA DIFERENCIA ENTRE FECHAS ES:  \n";
			std::cout << "----------------------------------\n";

			dateDifference(day1, day2, month1, month2, year1, year2);

			break;
		case 4:
			std::cout << "Ingrese la cantidad de dias que desee sumar: "; 
			std::cin >> plus; 

			std::cout << "\n  LA SUMA DA COMO RESULTADO:  \n";
			std::cout << "--------------------------------\n";
			std::cout << "Fecha orginal 1: "; formatDate(day1, month1, year1);
			std::cout << "Fecha modificada: "; plusDays(day1, month1, year1, plus); 
			std::cout << "\n"; 
			std::cout << "Fecha orginal 2: "; formatDate(day2, month2, year2);
			std::cout << "Fecha modificada: "; plusDays(day2, month2, year2, plus);

			break;
		case 5:
			std::cout << "Ingrese la cantidad de dias que desee restar: ";
			std::cin >> minus;

			std::cout << "\n  LA RESTA DA COMO RESULTADO:  \n";
			std::cout << "---------------------------------\n";
			std::cout << "Fecha orginal 1: "; formatDate(day1, month1, year1);
			std::cout << "Fecha modificada: "; minusDays(day1, month1, year1, minus);
			std::cout << "\n";
			std::cout << "Fecha orginal 2: "; formatDate(day2, month2, year2);
			std::cout << "Fecha modificada: "; minusDays(day2, month2, year2, minus);

			break;
		case 6:
			std::cout << "  EL RESULTADO ES:  \n"; 
			std::cout << "--------------------\n";
			distance = dateDistance(year1, year2); 
			std::cout << "La diferencia entre " << formatYear(year1) << " y " << formatYear(year2) << " es de: " << distance << std:: endl;
			ifLeapYear(year1, year2); 

			break;
		case 7:
			std::cout << "  LAS FECHAS EN FORMATO LARGO ES:  \n"; 
			std::cout << "-----------------------------------\n"; 

			std::cout << "La primera fecha: "; 
			if (day1 < 10) {
				std::cout << "0"; 
			}
			std::cout << day1 << " de " << longFormat(month1) << " del " << formatYear(year1); 
			std::cout << "\n";

			std::cout << "La primera fecha: ";
			if (day2 < 10) {
				std::cout << "0";
			}
			std::cout << day2 << " de " << longFormat(month2) << " del " << formatYear(year2);
			std::cout << "\n";

			break;
		case 8:
			std::cout << "Ha salido exitosamente.\n";
			break;
		default :
			std::cout << "LA OPCION QUE INDICO NO EXISTE.\n";
			break; 
		}

	} while (option != 8); 

	return 0; 
}