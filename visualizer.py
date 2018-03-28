from mpl_toolkits import mplot3d
from mpl_toolkits.mplot3d import Axes3D
from matplotlib import cm

import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as anim
import random



# Ejemplos de Funciones de Ploteo

# # Ejemplo No 1
# def fun(x, y):
#   return x + y

# fig = plt.figure()
# ax = fig.add_subplot(111, projection='3d')
# n = 10
# xs = [i for i in range(n) for _ in range(n)]
# ys = range(n) * n
# zs = [fun(x, y) for x,y in zip(xs,ys)]

# ax.scatter(xs, ys, zs)

# ax.set_xlabel('X Label')
# ax.set_ylabel('Y Label')
# ax.set_zlabel('Z Label')

# plt.show()


# # Ejemplo No 2
# def fun(x, y):
#   return x**2 + y

# fig = plt.figure()
# ax = fig.add_subplot(111, projection='3d')
# x = y = np.arange(-3.0, 3.0, 0.05)
# X, Y = np.meshgrid(x, y)
# zs = np.array([fun(x,y) for x,y in zip(np.ravel(X), np.ravel(Y))])
# Z = zs.reshape(X.shape)

# ax.plot_surface(X, Y, Z)

# ax.set_xlabel('X Label')
# ax.set_ylabel('Y Label')
# ax.set_zlabel('Z Label')

# plt.show()


# x = np.linspace(0, 6*np.pi, 100)
# y = np.sin(x)

# # You probably won't need this if you're embedding things in a tkinter plot...
# plt.ion()

# fig = plt.figure()
# ax = fig.add_subplot(111)
# line1, = ax.plot(x, y, 'r-') # Returns a tuple of line objects, thus the comma

# for phase in np.linspace(0, 10*np.pi, 500):
#     line1.set_ydata(np.sin(x + phase))
#     fig.canvas.draw()


# import matplotlib.pyplot as plt
# import numpy as np
# import time

# def demo(a):
# 	y = [xt*a+1 for xt in x]
# 	ax.plot(x,y)
# 	ax.set_ylim([0,15])

# if __name__ == '__main__':
#     plt.ion()
#     fig, ax = plt.subplots()
#     x = range(0,5)
#     for a in range(1,4):
#     	demo(a)
#     	plt.pause(3)
#     	plt.draw()





# # ====================================
# #             MAIN  PROGRAM
# # ====================================


plt.ion()

fig = plt.figure()
ax = Axes3D(fig)

# Contenedores
sequence_containing_x_vals = list(range(0, 10000))
#sequence_containing_x_vals = [1,2,3,4,5]
sequence_containing_y_vals = list(range(0, 10000))
#sequence_containing_y_vals = [1,2,3,4,5]
sequence_containing_z_vals = list(range(0, 10000))
#sequence_containing_z_vals = [1,2,3,4,5]

#random.shuffle(sequence_containing_x_vals)
#random.shuffle(sequence_containing_y_vals)
#random.shuffle(sequence_containing_z_vals)



# Reading File
f = open('10000_points_ackley.txt','r')

cont = 0
for line in f:

	y = line.split()
	# print(y)

	sequence_containing_x_vals[cont] = float(y[0])
	sequence_containing_y_vals[cont] = float(y[1])
	sequence_containing_z_vals[cont] = float(y[2])

	cont += 1

	# print(cont)

	





f.close()
# End Reading File



#plt.show()

for it in range(15):

	plt.cla() # This cleans the plot!

	#ax.set_ylim([-100,200]) # Seteamos los limites de nuestro plot

	# # Uncomment this for updating functions
	# # Values in our lists change over iterations( changes over time )
	# for i in range(5):
	# 	#sequence_containing_x_vals[i] += 1
	# 	#sequence_containing_y_vals[i] += 1
	# 	#sequence_containing_z_vals[i] += 1
	# 	random.shuffle(sequence_containing_x_vals)
	# 	random.shuffle(sequence_containing_y_vals)
	# 	random.shuffle(sequence_containing_z_vals)
	

	#print(sequence_containing_x_vals,sequence_containing_y_vals,sequence_containing_z_vals)

	#ax.scatter(sequence_containing_x_vals, sequence_containing_y_vals, sequence_containing_z_vals)
	#ax.plot_trisurf(sequence_containing_x_vals, sequence_containing_y_vals, sequence_containing_z_vals, cmap=cm.hot)
	ax.plot_trisurf(sequence_containing_x_vals, sequence_containing_y_vals, sequence_containing_z_vals, cmap=cm.hot, alpha=0.4)

	plt.pause(200)
	plt.draw()





#plt.show()

# # ====================================
# #              END  PROGRAM
# # ====================================