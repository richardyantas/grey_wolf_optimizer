from mpl_toolkits import mplot3d
from mpl_toolkits.mplot3d import Axes3D
from matplotlib import cm

import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as anim
import random



# # ====================================
# #             MAIN  PROGRAM
# # ====================================


plt.ion()

fig = plt.figure()
ax = Axes3D(fig)

n = 100 # Numero de Agentes(Lobos)
iters = 50 # Numero de iteraciones

guiding_x_vals = list(range(0, 3*iters))
guiding_y_vals = list(range(0, 3*iters))
guiding_z_vals = list(range(0, 3*iters))


# Reading Guiding Points File
f = open('00_guiding_points.txt','r')

cont1 = 0
for line in f:

	y = line.split()
	#print(y)

	guiding_x_vals[cont1] = float(y[0])
	guiding_y_vals[cont1] = float(y[1])
	guiding_z_vals[cont1] = float(y[2])

	cont1 += 1

f.close()
# End Reading File

# Reading Following Points File
f = open('01_following_points.txt','r')

following_x_vals = list(range(0, n*iters))
following_y_vals = list(range(0, n*iters))
following_z_vals = list(range(0, n*iters))

cont2 = 0
for line in f:

	y = line.split()
	#print(y)

	following_x_vals[cont2] = float(y[0])
	following_y_vals[cont2] = float(y[1])
	following_z_vals[cont2] = float(y[2])

	cont2 += 1

f.close()
# End Reading File


for it in range(cont1 // 3):
	print("Iteration:",it)

	plt.cla() # This cleans the plot!

	ax.set_xlim([-500,500]) # Seteamos los limites de nuestro plot
	ax.set_ylim([-500,500]) # Seteamos los limites de nuestro plot
	ax.set_zlim([-10,1000]) # Seteamos los limites de nuestro plot

	sub_x = guiding_x_vals[it*3:it*3+3]
	sub_y = guiding_y_vals[it*3:it*3+3]
	sub_z = guiding_z_vals[it*3:it*3+3]

	# print(it*3,it*3+3) // Verificamos los numeros
	ax.scatter(sub_x, sub_y, sub_z, color='red')

	sub_x = following_x_vals[it*n:it*n+n]
	sub_y = following_y_vals[it*n:it*n+n]
	sub_z = following_z_vals[it*n:it*n+n]
	#print(it*n,it*n+n) # Verificamos los numeros

	ax.scatter(sub_x, sub_y, sub_z, color='blue')
	#ax.plot_trisurf(sequence_containing_x_vals, sequence_containing_y_vals, sequence_containing_z_vals, cmap=cm.hot)
	#ax.plot_trisurf(sequence_containing_x_vals, sequence_containing_y_vals, sequence_containing_z_vals, cmap=cm.hot, alpha=0.4)

	plt.pause(1)
	plt.draw()

# # ====================================
# #              END  PROGRAM
# # ====================================