// angular
import { Component } from '@angular/core';
import { RouterModule } from '@angular/router';
import { CommonModule } from '@angular/common';

// angular material
import { MatCardModule } from '@angular/material/card';
import { MatButtonModule } from '@angular/material/button';
import { MatIconModule } from '@angular/material/icon';

@Component({
  selector: 'app-home-page',
  imports: [
    CommonModule,
    RouterModule,
    MatCardModule, 
    MatButtonModule, 
    MatIconModule
  ],
  templateUrl: './home-page.component.html',
  styleUrl: './home-page.component.scss',
})
export class HomePageComponent {
  sections = [
    {
      title: 'Sección 1',
      description: 'Explora la primera sección de nuestra aplicación.',
      image: 'assets/img/section1.jpg',
      link: '/seccion1'
    },
    {
      title: 'Sección 2',
      description: 'Descubre más sobre este apartado interesante.',
      image: 'assets/img/section2.jpg',
      link: '/seccion2'
    },
    {
      title: 'Sección 3',
      description: 'Visita esta sección especial de la aplicación.',
      image: 'assets/img/section3.jpg',
      link: '/seccion3'
    }
  ];
}
