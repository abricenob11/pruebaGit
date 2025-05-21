import matplotlib.pyplot as plt
import numpy as np

# Datos de ejemplo
x = np.linspace(0, 10, 100)
y1 = np.sin(x)
y2 = np.cos(x)

# Crear figura y ejes
fig, ax = plt.subplots(figsize=(10, 6))  # Tamaño personalizado, ancho y alto en pulgadas

# Graficar múltiples curvas con diferentes estilos
# marker es la forma del marcador
# markersize es el tamanio
# markerevery es cada cuando quieres que aparezca en el grafico el marker o el puntico de los datos
curve1 = ax.plot(x, y1, color='royalblue', linewidth=2, linestyle='-', 
                 marker='o', markersize=5, markevery=10, label='Seno')
curve2 = ax.plot(x, y2, color='crimson', linewidth=2, linestyle='--', 
                 marker='s', markersize=5, markevery=10, label='Coseno')

## Personalización Completa ##

# 1. Título y etiquetas
# el pad es como la distancia entre el titulo y el inicio del grafico
ax.set_title('Comparación de Funciones Trigonométricas', fontsize=14, pad=20)
ax.set_xlabel('Ángulo (radianes)', fontsize=12)
ax.set_ylabel('Valor de la función', fontsize=12)

# 2. Límites de los ejes
ax.set_xlim(0, 10)  # Rango del eje X
ax.set_ylim(-1.2, 1.2)  # Rango del eje Y


# 3. Leyenda (¡esto responde tu pregunta!)
# framealpha controla la transparenca del fondo o marco, 0 transparente, 1 opaco
ax.legend(title='Funciones', title_fontsize=12, fontsize=11, 
          loc='upper right', shadow=True, framealpha=1)

# 4. Cuadrícula
# el true para que se vean las lineas de la cuadricula
# el alpha para controlar la transparencia de la cuadricula 0 invisible 1 opaco
ax.grid(True, linestyle='--', alpha=0.7)

# 5. Ejes personalizados
ax.spines['top'].set_visible(False)    # Quitar borde superior
ax.spines['right'].set_visible(False) # Quitar borde derecho
ax.spines['left'].set_linewidth(1.5)   # Grosor borde izquierdo
ax.spines['bottom'].set_linewidth(1.5) # Grosor borde inferior

# 6. Marcadores de ejes
# ax.tick_params(axis='both', which='major', labelsize=10)

# 7. Texto y anotaciones
# ax.text(2, 0.5, 'Punto importante', fontsize=10, 
#        bbox=dict(facecolor='white', alpha=0.8))
# ax.annotate('Máximo', xy=(np.pi/2, 1), xytext=(np.pi/2+1, 0.8),
#           arrowprops=dict(arrowstyle='->'))

# Guardar figura
fig.savefig('grafico_personalizado.pdf', dpi=300, bbox_inches='tight')
plt.show()