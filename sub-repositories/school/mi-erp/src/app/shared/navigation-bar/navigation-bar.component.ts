//angular
import { ActivatedRoute, Router } from '@angular/router';  // manejar rutas y activarlas
import { Component } from '@angular/core';  //Necesario para declarar un componente

//angular material
import { MatIconModule } from '@angular/material/icon'; 


@Component({
  selector: 'app-navigation-bar',  //selector para usar el componente en el  HTML
  imports: [MatIconModule],  // Importamos el módulo de iconos de Angular Material
  templateUrl: './navigation-bar.component.html',  //plantilla donde se define el HTML del componente
  styleUrl: './navigation-bar.component.scss'  
})

export class NavigationBarComponent {
  constructor (  //inyectamos el servicio y las rutas
    private router: Router,  // Paraa navegar entre páginas
    private route:ActivatedRoute,  //información de la ruta actual

    ) { }

  navigateToHome(){  // Función que nos lleva a la home
    this.router.navigate(['/']); 
  }

  navigateToAbout() {  // Función para ir a la página "About"
    this.router.navigate(['/aplicaciones']);  
  }

  navigateToContent() {  // Función para ir a la página "Content"
    this.router.navigate(['/comunidad']); 
  }

  logout() {  // Cuando el usuario hace logout
    this.router.navigate(['/login']);  // Después de logout, lo mandamos a la página de login
  }

}
