"""
Desarrolle un programa que calcule “qué nota necesito para aprobar” en la tercera
solemne considerando las siguientes ponderaciones. Nota 1: 25%, Nota 2: 25%, Nota
3: 30%, Controles: 20%. El programa deberá solicitar nota 1, nota 2 y la nota de
controles. Considere que la nota final de aprobación es de un 4.0
"""

nota1=float(input("grade 1 (25%): "))
nota2=float(input("grade 2 (25%): "))
controles=float(input("grade controles (20%): "))

nota3= (4-(nota1*25/100 + nota2*25/100 + controles*20/100))*(100/30)
print(f"you need a {nota3} (30%) in your next test")
