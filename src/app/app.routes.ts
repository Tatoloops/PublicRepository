import { Routes } from '@angular/router';
import { HomePageComponent } from './pages/home-page/home-page.component';
import { ScriptsPageComponent } from './pages/scripts-page/scripts-page.component';
import { SchoolPageComponent } from './pages/school-page/school-page.component';
import { ProjectsPageComponent } from './pages/projects-page/projects-page.component';


export const routes: Routes = [
    { path: '', redirectTo: 'home', pathMatch: 'full', component: HomePageComponent},
    { path: 'scripts', component: ScriptsPageComponent },
    { path: 'school', component: SchoolPageComponent },
    { path: 'projects', component: ProjectsPageComponent },
];
