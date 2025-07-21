import { Component } from '@angular/core';
import { CommonModule } from '@angular/common';
import { MatTreeModule } from '@angular/material/tree';
import { MatIconModule } from '@angular/material/icon';
import { MatButtonModule } from '@angular/material/button';
import { MatTreeNestedDataSource } from '@angular/material/tree';
import { NestedTreeControl } from '@angular/cdk/tree';

interface DocumentoNode {
  name: string;
  children?: DocumentoNode[];
}

@Component({
  selector: 'app-aplicacion-documentos',
  standalone: true,
  imports: [CommonModule, MatTreeModule, MatIconModule, MatButtonModule],
  templateUrl: './aplicacion-documentos.component.html',
  styleUrl: './aplicacion-documentos.component.scss'
})
export class AplicacionDocumentosComponent {
  treeControl = new NestedTreeControl<DocumentoNode>(node => node.children);
  dataSource = new MatTreeNestedDataSource<DocumentoNode>();

  documentos: DocumentoNode[] = [
    {
      name: 'Reportes',
      children: [
        { name: 'Ventas.pdf' },
        { name: 'Inventario.xlsx' }
      ]
    },
    {
      name: 'Facturas',
      children: [
        { name: 'Enero.docx' },
        { name: 'Febrero.docx' }
      ]
    },
    { name: 'Notas.txt' }
  ];

  selectedDocument: string | null = null;

  constructor() {
    this.dataSource.data = this.documentos;
  }

  hasChild = (_: number, node: DocumentoNode) => !!node.children && node.children.length > 0;

  selectDocument(documentName: string) {
    this.selectedDocument = documentName;
  }
  isSelected(node: DocumentoNode): boolean {
  return this.selectedDocument === node.name;
}

}
