//angular
import { Component } from '@angular/core';
import { Router,ActivatedRoute } from '@angular/router';

//angular material
import { MatIconModule} from '@angular/material/icon';
import { MatButtonModule } from '@angular/material/button';
import { CommonModule } from '@angular/common';
import { MatButtonToggleModule} from '@angular/material/button-toggle';

@Component({
  selector: 'app-navigation-comp',
  imports: [CommonModule,
    MatIconModule,
    MatButtonModule,
    MatButtonToggleModule
  ],
  templateUrl: './navigation-comp.component.html',
  styleUrl: './navigation-comp.component.scss'
})
export class NavigationCompComponent {
  constructor(private router: Router, private route: ActivatedRoute) { }


  //navigation methods
  navigateToHome() {
    this.router.navigate(['/home']);
  }
  navigateToScripts() {
    this.router.navigate(['/scripts']);
  }
  navigateToSchool() {
    this.router.navigate(['/school']);
  }
  navigateToProjects() {
    this.router.navigate(['/projects']);
  }

  // theme
  currentTheme = 'theme-ultraviolet-default';
  
  setTheme(themeClass: string) {
    this.currentTheme = themeClass;
    document.body.className = '';
    document.body.classList.add(themeClass);
  }


}
