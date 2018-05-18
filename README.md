# practica_5

So why the order is atan2(yj - yi,xj - xi) to calculate the angle
where "i" is the particle we are calculating the acceleration of.
      "j" iterates over all of the other particles.
      
The answer is that the formula could be described better as:

angle of a particle taking another particles as reference = atan2(y-yref,x-xref)

Why point - point_reference --> That is because this represents the position of point taking the origin at the point of reference.

So thats it.

NOTICE that in the definition of angleBetweenParticles(pi,pj), the difference is taken as pj - pi

So a better notation for these function would be angleBetweenParticles(reference particle, particle)

Maybe I will renotate the code later
