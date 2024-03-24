package listados;
//1.	Generar e imprimir los "n" primeros números pares.
import java.util.Scanner;

public class ciclos {
	public static void main(String[] args){
		int selection;
		Scanner input= new Scanner(System.in);
		System.out.println("Seleccione Ejercicio a realizar: ");
		System.out.println("1 - Generar e imprimir los \"n\" primeros números pares.");
		System.out.println("2 - Generar e imprimir los \"n\" primeros números impares.");
		System.out.println("3 - Imprimir la sumatoria de los \"N\" primeros múltiplos de 3, con \"N\" ingresado desde teclado.");
		System.out.println("4 - Ingresar una cantidad \"N\" de números y permita además imprimir la cantidad total de números múltiplos de 10.");
		System.out.println("5 - Ingresar una cantidad \"M\" determinada de caracteres (alfanuméricos) y que imprima la cantidad total de vocales que fueron ingresadas.");
		System.out.println("6 -	Ingresar una cantidad \"N\" de caracteres alfanuméricos y que cuente e imprima la cantidad total de consonantes.");
		System.out.println("7 - Escribir un programa para determinar cuantas cifras tiene un entero n.");
		System.out.println("8 -	Escribir un programa que lea un número entero de 5 cifras y que invierta su orden, como lo muestra el ejemplo. 12345 transformado a 54321.");
		System.out.println("9 -	Realice un programa que permita sumar los digitos de un número entero iongresado por teclado. Ejemplo: Si el número ingresado es  5634 el algoritmo debería sumar 5+6+3+4.");
		System.out.println("10-	Escribir un algoritmo que determine si un número entero “n” es o no primo. ");
		System.out.println("11-	Las potencias de 2 son 1, 2, 4, 8, 16, 32, 64, etc. Para obtener la siguiente potencia de 2, se multiplica la anterior por 2. Usando ciclos, escriba el algoritmo para imprimir la primera potencia de 2 mayor que mil.");
		System.out.println("12-	Calcular el factorial de un número ingresado por teclado.");
		System.out.println("13-	Generar la siguiente sumatoria: S = 1 + 2 + 3 + . . . + N 	y finalmente imprima S.");
		System.out.println("14-	Generar la siguiente sumatoria : S = 1^n + 2^n + 3^n + 4^n + . . . + n^n	y finalmente imprima S.");
		System.out.println("15-	Generar las sumatorias : S = n*1 + n*2 + n*3 + n*4 + ....... + n*n");
		System.out.println("16-	Generar la serie  E= 1 - (x^2)/3! + (x^3)/4! - (x^4)/5! + .... +- (x^n)/(n+1)!  y finalmente imprima E.");
		do{
			selection = input.nextInt();
		}
		while (selection <0 || selection >16);
		if (selection==0){
			return;
		}
		if (selection ==1){
			System.out.println("1 - Generar e imprimir los \"n\" primeros números pares.");
			System.out.print("	Ingrese \'n\': ");
			int n = input.nextInt();
			l01(n);
		}
		else if (selection==2){
			System.out.println("2 - Generar e imprimir los \"n\" primeros números impares.");
			System.out.print("	Ingrese \'n\': ");
			int n = input.nextInt();
			l02(n);
		}
		else if (selection==3){
			System.out.println("3 - Imprimir la sumatoria de los \"N\" primeros múltiplos de 3, con \"N\" ingresado desde teclado.");
			System.out.print("	Ingrese \'n\': ");
			int n = input.nextInt();
			l03(n);
		}

		return;
	}
	public static void l01(int n){
		//1 - Generar e imprimir los \"n\" primeros números pares.
		for (int i=1;i<=n;i++){
			System.out.print(" "+ i*2);
		}
		return;
	}
	public static void l02(int n){
		//2 - Generar e imprimir los \"n\" primeros números impares.
		for (int i=1;i<=n;i++){
			System.out.print(" "+ ((i*2)-1));
		}
		return;
	}
	public static void l03(int n){
		//3 - Imprimir la sumatoria de los \"N\" primeros múltiplos de 3, con \"N\" ingresado desde teclado.
			System.out.print(" "+ (int)((3*Math.pow(n,2)+3*n)/2));
		return;
	}
	public static void l04(int n){
		//4 - Ingresar una cantidad \"N\" de números y permita además imprimir la cantidad total de números múltiplos de 10.
			System.out.print(" "+ (int)((3*Math.pow(n,2)+3*n)/2));
		return;
	}
	public static void l05(int n){
		//5 - Ingresar una cantidad \"M\" determinada de caracteres (alfanuméricos) y que imprima la cantidad total de vocales que fueron ingresadas.
			System.out.print(" "+ (int)((3*Math.pow(n,2)+3*n)/2));
		return;
	}
}