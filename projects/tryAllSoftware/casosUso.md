## Diagrama de actividades

– Actividades / acciones.
– Decisiones.
– Swimlanes o carriles.
– Objetos.
– Barras de sincronización (Fork/Join)

## Casos de uso
CU1 - Configurar zonas de cultivo:
Como admin, quiero definir zonas de cultivo en función del terreno y cultivo,
para personalizar la gestión agrícola.

CU2 - Programar riego:
Como usuario o admin, quiero definir cuándo y cuánto regar según predicciones, para optimizar el uso del agu

CU3 - Monitorear variables en vivo:
Como usuario, quiero visualizar datos en tiempo real desde los sensores, para monitorear el estado del cultivo.

CU4 - Emitir alertas inteligentes:
Como sistema, quiero notificar si hay riesgos como sequía o sobreuso, para prevenir pérdidas.

CU5 - Analizar datos históricos:
Como usuario, quiero consultar y comparar información histórica, para entender tendencias y tomar mejores decisiones.

CU6 - Ajustar riego automáticamente:
Como sistema, quiero modificar el riego de forma autónoma, para adaptarme a las condiciones actuales.

CU7 - Visualizar sugerencias:
Como usuario, quiero recibir sugerencias personalizadas para mejorar el riego.

CU8 - Control remoto del sistema:
Como usuario, quiero gestionar el sistema a distancia, validando decisiones con la IA.

CU9 - Generar informes de cumplimiento:
Como servidor central, quiero exportar reportes para auditorías.

CU10 - Autenticarse y gestionar sesión:
Como usuario, quiero iniciar sesión según mi rol, para acceder a las funciones asignadas.

## Casos de uso

1. CU1 (Configurar zonas de cultivo) → CU2 (Programar riego) : <<include>>
Por qué:
Configurar las zonas de cultivo es un paso fundamental para poder programar el riego. El riego debe aplicarse en zonas definidas, por lo que cuando se programa el riego, se asume que las zonas ya están configuradas.

Relación include: significa que para poder programar el riego, el sistema necesariamente necesita haber definido zonas de cultivo previamente o al menos se apoya en esa información.

2. CU2 (Programar riego) → CU4 (Emitir alertas inteligentes) : <<extend>>
Por qué:
Cuando un usuario o administrador programa el riego, el sistema puede emitir alertas si detecta condiciones de riesgo (por ejemplo, riego excesivo, horarios no adecuados, o predicciones de sequía).

Relación extend: significa que emitir alertas es una acción que puede ocurrir como consecuencia de programar riego, pero no siempre sucede; es opcional y condicional.

3. CU2 (Programar riego) → CU6 (Ajustar riego automáticamente) : <<include>>
Por qué:
El sistema puede tomar la programación inicial hecha por el usuario y, basado en sensores y condiciones en tiempo real, ajustar automáticamente el riego para optimizarlo.

Relación include: implica que ajustar riego automáticamente es parte del proceso de programación, una función integrada en el sistema que complementa la tarea del usuario.

4. CU2 (Programar riego) → CU7 (Visualizar sugerencias) : <<include>>
Por qué:
Mientras el usuario programa el riego, puede recibir sugerencias personalizadas del sistema para mejorar la eficiencia del agua y la salud de los cultivos.

Relación include: las sugerencias forman parte del proceso de programación, enriqueciendo la experiencia y resultado.

5. CU3 (Monitorear variables en vivo) → CU4 (Emitir alertas inteligentes) : <<extend>>
Por qué:
Monitorear en tiempo real las variables del cultivo (humedad, temperatura, etc.) puede generar alertas inmediatas si se detectan riesgos (sequía, inundación, etc.).

Relación extend: las alertas se generan sólo si las condiciones de monitoreo lo requieren.

6. CU4 (Emitir alertas inteligentes) → CU8 (Control remoto del sistema) : <<include>>
Por qué:
Cuando el sistema emite una alerta, el usuario puede actuar para corregir el problema desde cualquier lugar usando el control remoto.

Relación include: el control remoto es parte de la respuesta al recibir una alerta.

7. CU5 (Analizar datos históricos) → CU7 (Visualizar sugerencias) : <<include>>
Por qué:
El análisis histórico de datos permite generar recomendaciones y sugerencias personalizadas para mejorar futuros ciclos de riego.

Relación include: la visualización de sugerencias se basa en la interpretación de esos datos históricos.

8. CU6 (Ajustar riego automáticamente) → CU4 (Emitir alertas inteligentes) : <<include>>
Por qué:
Cuando el sistema ajusta el riego automáticamente, puede detectar condiciones anómalas o riesgos, lo que puede desencadenar alertas.

Relación include: las alertas son parte integral del ajuste automático para prevenir problemas.

9. CU10 (Autenticarse y gestionar sesión) → (todos los casos con actores)
Por qué:
Para acceder a cualquier funcionalidad (configurar zonas, programar riego, monitorear, etc.), es necesario que el usuario esté autenticado.

Relación: normalmente, se suele representar esta relación para enfatizar que todos estos casos requieren sesión activa. En diagramas no siempre se pone flecha a cada caso para no sobrecargar, pero conceptualmente es fundamental.

Resumen conceptual
Include: indica que el caso de uso A es parte esencial y necesario para que el caso de uso B funcione (se “incluye” siempre).

Extend: indica que el caso de uso A puede extender funcionalidad de B en ciertas condiciones (es opcional, condicional).

Asociación entre actores y casos: que un actor puede ejecutar o interactuar con ese caso de uso.