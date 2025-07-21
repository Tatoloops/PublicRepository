import { ComponentFixture, TestBed } from '@angular/core/testing';

import { AplicacionDocumentosComponent } from './aplicacion-documentos.component';

describe('AplicacionDocumentosComponent', () => {
  let component: AplicacionDocumentosComponent;
  let fixture: ComponentFixture<AplicacionDocumentosComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      imports: [AplicacionDocumentosComponent]
    })
    .compileComponents();

    fixture = TestBed.createComponent(AplicacionDocumentosComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
