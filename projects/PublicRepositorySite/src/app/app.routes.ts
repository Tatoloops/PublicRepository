// angular
import { Routes } from '@angular/router';

// pages
import { HomePageComponent } from './pages/home-page/home-page.component';
import { ScriptsPageComponent } from './pages/scripts-page/scripts-page.component';
import { SchoolPageComponent } from './pages/school-page/school-page.component';
import { ProjectsPageComponent } from './pages/projects-page/projects-page.component';


export const routes: Routes = [
    { path: '', redirectTo: 'home', pathMatch: 'full'},
    { path: 'home', component: HomePageComponent },
    { path: 'scripts', component: ScriptsPageComponent },
    { path: 'school', component: SchoolPageComponent },
    { path: 'projects', component: ProjectsPageComponent },
];
