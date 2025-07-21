import { Component } from '@angular/core';
import { CommonModule } from '@angular/common';
import { MatCardModule } from '@angular/material/card';
import { MatIconModule } from '@angular/material/icon';
import { MatButtonModule } from '@angular/material/button';

interface Servicio {
  icon: string;
  title: string;
}

interface CategoriaServicios {
  categoria: string;
  servicios: Servicio[];
}

@Component({
  selector: 'app-servicios-dashboard',
  standalone: true,
  imports: [CommonModule, MatCardModule, MatIconModule, MatButtonModule],
  templateUrl: './servicios-dashboard.component.html',
  styleUrl: './servicios-dashboard.component.scss'
})
export class ServiciosDashboardComponent {
  categorias: CategoriaServicios[] = [
    {
      categoria: 'Consultoría y Gestión',
      servicios: [
        { icon: 'business_center', title: 'Consultoría de Negocios' },
        { icon: 'verified', title: 'Auditorías y Certificaciones' },
        { icon: 'analytics', title: 'Consultoría Financiera' },
        { icon: 'assignment', title: 'Gestión de Proyectos' },
        { icon: 'rule', title: 'Control de Calidad' },
        { icon: 'gavel', title: 'Asesoría Legal y Fiscal' },
        { icon: 'account_balance', title: 'Outsourcing Contable' },
        { icon: 'description', title: 'Gestión de Contratos' },
        { icon: 'insights', title: 'Análisis de Datos Empresariales' }
      ]
    },
    {
      categoria: 'Servicios Técnicos',
      servicios: [
        { icon: 'computer', title: 'Soporte Informático' },
        { icon: 'build', title: 'Mantenimiento de Infraestructura' },
        { icon: 'router', title: 'Instalación de Redes y Servidores' },
        { icon: 'memory', title: 'Venta y Reparación de Equipos' },
        { icon: 'cloud', title: 'Hosting y Dominios Web' },
        { icon: 'security', title: 'Seguridad Informática' },
        { icon: 'developer_mode', title: 'Integración de Software' },
        { icon: 'code', title: 'Desarrollo de Aplicaciones' }
      ]
    },
    {
      categoria: 'Logística y Almacenes',
      servicios: [
        { icon: 'warehouse', title: 'Gestión de Almacenaje' },
        { icon: 'local_shipping', title: 'Transporte y Distribución' },
        { icon: 'autorenew', title: 'Logística Inversa' },
        { icon: 'directions_car', title: 'Alquiler de Vehículos de Carga' }
      ]
    },
    {
      categoria: 'Marketing y Publicidad',
      servicios: [
        { icon: 'campaign', title: 'Alquiler de Anuncios Publicitarios' },
        { icon: 'brush', title: 'Diseño Gráfico Corporativo' },
        { icon: 'social_distance', title: 'Gestión de Redes Sociales' },
        { icon: 'video_library', title: 'Producción Audiovisual' },
        { icon: 'photo_camera', title: 'Fotografía Comercial' },
        { icon: 'dynamic_feed', title: 'Campañas Publicitarias' },
        { icon: 'language', title: 'Desarrollo Web y SEO' }
      ]
    },
    {
      categoria: 'Recursos Humanos',
      servicios: [
        { icon: 'people', title: 'Gestión de Nómina' },
        { icon: 'person_search', title: 'Adquisición de Talentos' },
        { icon: 'school', title: 'Capacitación y Formación' },
        { icon: 'assessment', title: 'Evaluación de Desempeño' },
        { icon: 'vacation', title: 'Gestión de Vacaciones' },
        { icon: 'engineering', title: 'Head Hunting' },
        { icon: 'group_add', title: 'Personal Temporal' }
      ]
    },
    {
      categoria: 'Servicios Generales',
      servicios: [
        { icon: 'build_circle', title: 'Personal de Mantenimiento' },
        { icon: 'local_shipping', title: 'Servicios de Mensajería' },
        { icon: 'cleaning_services', title: 'Limpieza de Oficinas' },
        { icon: 'restaurant', title: 'Servicios de Catering' },
        { icon: 'local_taxi', title: 'Transporte Privado' },
        { icon: 'chair', title: 'Alquiler de Mobiliario' },
        { icon: 'content_cut', title: 'Peluquería y Estética' }
      ]
    }
  ];
}
