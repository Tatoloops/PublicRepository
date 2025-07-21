import { Component } from '@angular/core';
import { CommonModule } from '@angular/common';
import { MatCardModule } from '@angular/material/card';
import { MatIconModule } from '@angular/material/icon';
import { MatButtonModule } from '@angular/material/button';

@Component({
  selector: 'app-dashboard',
  standalone: true,
  imports: [CommonModule, MatCardModule, MatIconModule, MatButtonModule],
  templateUrl: './dashboard.component.html',
  styleUrl: './dashboard.component.scss'
})
export class DashboardComponent {
  funcionalidades = [
    { icon: 'inventory', title: 'Inventario', color: '#3f51b5', favorito: false },
    { icon: 'shopping_cart', title: 'Ventas', color: '#4caf50', favorito: false },
    { icon: 'receipt_long', title: 'Facturación', color: '#ff9800', favorito: false },
    { icon: 'payments', title: 'Cuentas por Cobrar', color: '#f44336', favorito: false },
    { icon: 'people', title: 'Clientes', color: '#9c27b0' , favorito: false},
    { icon: 'engineering', title: 'Proveedores', color: '#009688', favorito: false },
    { icon: 'insights', title: 'Reportes', color: '#795548', favorito: false },
    { icon: 'settings', title: 'Configuración', color: '#607d8b', favorito: false },
    { icon: 'assignment', title: 'Documentos', color: '#607d8b', favorito: false }
  ];

  toggleFavorito(item: any) {
    item.favorito = !item.favorito;
  }

}
