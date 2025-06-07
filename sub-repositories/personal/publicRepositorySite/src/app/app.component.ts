import { Component } from '@angular/core';
import { RouterOutlet } from '@angular/router';
import { NavigationCompComponent } from "./shared/components/navigation-comp/navigation-comp.component";
import { FooterCompComponent } from "./shared/components/footer-comp/footer-comp.component";

@Component({
  selector: 'app-root',
  imports: [RouterOutlet, NavigationCompComponent, FooterCompComponent],
  templateUrl: './app.component.html',
  styleUrl: './app.component.scss'
})
export class AppComponent {
  title = 'PublicRepositorySite';
}
