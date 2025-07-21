import { Routes } from '@angular/router';
import { DashboardComponent } from './features/dashboard/dashboard.component';
import { AplicacionDocumentosComponent } from './features/aplicaciones/aplicacion-documentos/aplicacion-documentos.component';
import { ServiciosDashboardComponent } from './features/servicios/servicios-dashboard/servicios-dashboard.component';

export const routes: Routes = [
    { path: '', component: DashboardComponent, pathMatch: 'full' },
    { path: 'aplicaciones/documentos', component: AplicacionDocumentosComponent },
    { path: 'servicios', component: ServiciosDashboardComponent },
];
