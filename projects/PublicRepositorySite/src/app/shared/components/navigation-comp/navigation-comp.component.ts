//angular
import { Component } from '@angular/core';
import { Router,ActivatedRoute } from '@angular/router';

//angular material
import {MatIconModule} from '@angular/material/icon';

@Component({
  selector: 'app-navigation-comp',
  imports: [MatIconModule],
  templateUrl: './navigation-comp.component.html',
  styleUrl: './navigation-comp.component.scss'
})
export class NavigationCompComponent {
  constructor(private router: Router, private route: ActivatedRoute) { }

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
}
