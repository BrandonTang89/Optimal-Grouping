# Optimal-Grouping
An algorithm to maximise net happiness amongst people at social events.

<b>About (Function)</b>
Social gatherings usually have guests are divided into groups of x people (such as for sitting around a table). However, many organisers fail to accomplish this task logically and instead naively ask the guests to divide amongst themselves, assuming that this arrangement would be optimsal. However, such an arrangement makes it awkward for people with little friends/connetions to find a comfortable position and is geneally just a pain for people to go through.<br>

As such, <b>this algorithm aims to optimally divide n people into groups of x people such that the overall comfort level is the highest.</b>

<h3>Mechanism (Attempting to be less technical)</h3>
<ul>
  <li>Each guest lists a set of people they are comfortable with and how comfortable they are with that person.</li>
  <li>The sum of comfort that a person has towards others is 1</li>
  <li>If 2 people are in the same group, their comfort towards each other is added to the total comfort for that permutation</li>
  <li>The algorithm bruteforces permutations of the groups such that the total comfort for the guests is max</li>
 </ul>
 
 <h3>Mechanism (Technical)</h3>
<ul>
  <li>Guests are modelled as vertices and friendships/connections are modelled as edges in a directional weighted graph</li>
  <li>Each guest [g] gives a rating [R<sub>i</sub>] to the each other guest [i]</li>v
  <li>The sum of weights edges away from each vertex is 1</li>
  <li>Thus the weight of each edge [g -> i] is \frac{R<sub>i</sub>}{\sum R<sub>i</sub>}>/li>
</ul>
