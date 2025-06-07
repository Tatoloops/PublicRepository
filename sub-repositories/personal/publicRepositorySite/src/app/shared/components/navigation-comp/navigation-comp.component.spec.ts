import { ComponentFixture, TestBed } from '@angular/core/testing';

import { NavigationCompComponent } from './navigation-comp.component';

describe('NavigationCompComponent', () => {
  let component: NavigationCompComponent;
  let fixture: ComponentFixture<NavigationCompComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      imports: [NavigationCompComponent]
    })
    .compileComponents();

    fixture = TestBed.createComponent(NavigationCompComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
