import { ComponentFixture, TestBed } from '@angular/core/testing';

import { ScriptsPageComponent } from './scripts-page.component';

describe('ScriptsPageComponent', () => {
  let component: ScriptsPageComponent;
  let fixture: ComponentFixture<ScriptsPageComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      imports: [ScriptsPageComponent]
    })
    .compileComponents();

    fixture = TestBed.createComponent(ScriptsPageComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
