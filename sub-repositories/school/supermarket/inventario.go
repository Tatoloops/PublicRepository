package main

// Tomas Castillo A

import (
	"fmt"
)

type Producto struct {
	SKU    int
	Nombre string
	Precio int
	Stock  int
}

type Movimiento struct {
	Tipo          string
	SKU           int
	Nombre        string
	Cantidad      int
	PrecioUnit    int
	ValorTotal    int
	CostoUnitario int // Solo se usa en compra
}

var inventario = map[int]*Producto{
	1: {1, "Smart TV", 280000, 50},
	2: {2, "Refrigerador", 1500000, 20},
	3: {3, "Microondas", 200000, 80},
	4: {4, "Lavadora", 650000, 100},
	5: {5, "Comedor", 5500000, 5},
}

var movimientos []Movimiento

func main() {
	for {
		fmt.Println("\n===== MENÚ =====")
		fmt.Println("1. Ver inventario")
		fmt.Println("2. Registrar compra")
		fmt.Println("3. Registrar venta")
		fmt.Println("4. Ver reporte de movimientos")
		fmt.Println("5. Salir")
		fmt.Print("Seleccione una opción: ")

		var opcion int
		fmt.Scanln(&opcion)

		switch opcion {
		case 1:
			mostrarInventario()
		case 2:
			registrarCompra()
		case 3:
			registrarVenta()
		case 4:
			mostrarMovimientos()
		case 5:
			return
		default:
			fmt.Println("Opción no válida")
		}
	}
}

func mostrarInventario() {
	fmt.Println("\n===== INVENTARIO =====")
	fmt.Printf("%-5s %-15s %-10s %-5s\n", "SKU", "Producto", "Precio", "Stock")
	for _, p := range inventario {
		fmt.Printf("%-5d %-15s %-10d %-5d\n", p.SKU, p.Nombre, p.Precio, p.Stock)
	}
}

func registrarCompra() {
	var sku, cantidad, costoUnitario int

	fmt.Println("\n===== REGISTRAR COMPRA =====")
	fmt.Print("Ingrese SKU: ")
	fmt.Scanln(&sku)

	prod, existe := inventario[sku]
	if !existe {
		fmt.Println("Producto no encontrado")
		return
	}

	fmt.Printf("Producto: %s\n", prod.Nombre)
	fmt.Print("Cantidad a comprar: ")
	fmt.Scanln(&cantidad)
	fmt.Print("Costo unitario: ")
	fmt.Scanln(&costoUnitario)

	prod.Stock += cantidad

	mov := Movimiento{
		Tipo:          "Compra",
		SKU:           sku,
		Nombre:        prod.Nombre,
		Cantidad:      cantidad,
		PrecioUnit:    prod.Precio,
		ValorTotal:    cantidad * costoUnitario,
		CostoUnitario: costoUnitario,
	}
	movimientos = append(movimientos, mov)

	fmt.Println("Compra registrada con éxito.")
}

func registrarVenta() {
	var sku, cantidad int

	fmt.Println("\n===== REGISTRAR VENTA =====")
	fmt.Print("Ingrese SKU: ")
	fmt.Scanln(&sku)

	prod, existe := inventario[sku]
	if !existe {
		fmt.Println("Producto no encontrado")
		return
	}

	fmt.Printf("Producto: %s\n", prod.Nombre)
	fmt.Printf("Stock disponible: %d\n", prod.Stock)
	fmt.Print("Cantidad a vender: ")
	fmt.Scanln(&cantidad)

	if cantidad > prod.Stock {
		fmt.Println("Stock insuficiente.")
		return
	}

	prod.Stock -= cantidad

	valorVenta := cantidad * prod.Precio
	mov := Movimiento{
		Tipo:       "Venta",
		SKU:        sku,
		Nombre:     prod.Nombre,
		Cantidad:   cantidad,
		PrecioUnit: prod.Precio,
		ValorTotal: valorVenta,
	}
	movimientos = append(movimientos, mov)

	fmt.Printf("Venta registrada. Valor total: %d\n", valorVenta)
}

func mostrarMovimientos() {
	fmt.Println("\n===== REPORTE DE MOVIMIENTOS =====")
	fmt.Printf("%-8s %-5s %-15s %-8s %-12s %-12s\n", "Tipo", "SKU", "Producto", "Cantidad", "Unitario", "Total")
	for _, m := range movimientos {
		if m.Tipo == "Compra" {
			fmt.Printf("%-8s %-5d %-15s %-8d %-12d %-12d\n", m.Tipo, m.SKU, m.Nombre, m.Cantidad, m.CostoUnitario, m.ValorTotal)
		} else {
			fmt.Printf("%-8s %-5d %-15s %-8d %-12d %-12d\n", m.Tipo, m.SKU, m.Nombre, m.Cantidad, m.PrecioUnit, m.ValorTotal)
		}
	}
}
