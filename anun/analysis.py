import matplotlib

import numpy

from matplotlib import pyplot
#from pylab import genfromtxt
data = numpy.genfromtxt("thedata.txt")

data1 = []
data2 = []


hist1 = pyplot.figure()
ahist1 = hist1.add_subplot(111)
ahist1.hist(data[:,7], bins=50, normed=0)
hist1.savefig('ahist1.png', bbox_inches='tight')
