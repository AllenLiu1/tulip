
.. |br| raw:: html

   <br />

.. |bstart| raw:: html

   <b>

.. |bend| raw:: html

   </b>

.. |istart| raw:: html

   <i>

.. |iend| raw:: html

   </i>

.. |listart| raw:: html

   <li>

.. |liend| raw:: html

   </li>

.. |ulstart| raw:: html

   <ul>

.. |ulend| raw:: html

   </ul>

.. |pstart| raw:: html

   <p>

.. |pend| raw:: html

   </p>


.. py:currentmodule:: tulip

.. _tulippluginsdoc:

Tulip plugins documentation
===========================


In this section, you can find some documentation regarding the C++ algorithm plugins bundled in the Tulip 
software but also with the Tulip Python modules installable through the pip tool.
In particular, an exhaustive description of the input and output parameters for each plugin is given.
To learn how to call all these algorithms in Python, you can refer to the :ref:`Applying an algorithm on a graph <applyGraphAlgorithm>` section.
The plugins documentation is ordered according to their type.

.. warning:: If you use the Tulip Python bindings trough the classical Python interpreter, some plugins
             (Color Mapping, Convolution Clustering, File System Directory, GEXF, SVG Export, Website)
             require the :mod:`tulipgui` module to be imported before they can be called as they use Qt under the hood.


Algorithm
---------

.. _algorithmpluginsdoc:

To call these plugins, you must use the :meth:`tlp.Graph.applyAlgorithm` method. See also :ref:`Calling a general algorithm on a graph <callGeneralAlgorithm>` for more details.

Acyclic
^^^^^^^

Description
"""""""""""

Tests whether a graph is acyclic or not.

Parameters
""""""""""

+--------+---------+-----------+-------------+------------------------------------+
| name   | type    | default   | direction   | description                        |
+========+=========+===========+=============+====================================+
| result | Boolean |           | output      | Whether the test succeeded or not. |
+--------+---------+-----------+-------------+------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Acyclic', graph)

  success = graph.applyAlgorithm('Acyclic', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Biconnected
^^^^^^^^^^^

Description
"""""""""""

Tests whether a graph is biconnected or not.

Parameters
""""""""""

+--------+---------+-----------+-------------+------------------------------------+
| name   | type    | default   | direction   | description                        |
+========+=========+===========+=============+====================================+
| result | Boolean |           | output      | Whether the test succeeded or not. |
+--------+---------+-----------+-------------+------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Biconnected', graph)

  success = graph.applyAlgorithm('Biconnected', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Connected
^^^^^^^^^

Description
"""""""""""

Tests whether a graph is connected or not.

Parameters
""""""""""

+--------+---------+-----------+-------------+------------------------------------+
| name   | type    | default   | direction   | description                        |
+========+=========+===========+=============+====================================+
| result | Boolean |           | output      | Whether the test succeeded or not. |
+--------+---------+-----------+-------------+------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Connected', graph)

  success = graph.applyAlgorithm('Connected', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Curve edges
^^^^^^^^^^^

Description
"""""""""""

Computes quadratic or cubic bezier paths for edges

Parameters
""""""""""

+-----------------+-------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+-------------------------------------------------------------------------------------------------------------+
| name            | type                          | default                                                                                                                                                                                                                                                                                                                                                                                 | direction   | description                                                                                                 |
+=================+===============================+=========================================================================================================================================================================================================================================================================================================================================================================================+=============+=============================================================================================================+
| layout          | :class:`tlp.LayoutProperty`   | viewLayout                                                                                                                                                                                                                                                                                                                                                                              | input       | The input layout of the graph.                                                                              |
+-----------------+-------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+-------------------------------------------------------------------------------------------------------------+
| curve roundness | floating point number         | 0.5                                                                                                                                                                                                                                                                                                                                                                                     | input       | Parameter for tweaking the curve roundness. The value range is from 0 to 1 with a maximum roundness at 0.5. |
+-----------------+-------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+-------------------------------------------------------------------------------------------------------------+
| curve type      | :class:`tlp.StringCollection` | QuadraticContinuous |br| |br| Values for that parameter: |br| QuadraticContinuous  |br| QuadraticDiscrete  |br| QuadraticDiagonalCross  |br| QuadraticStraightCross  |br| QuadraticHorizontal  |br| QuadraticVertical  |br| CubicContinuous  |br| CubicVertical  |br| CubicDiagonalCross  |br| CubicVerticalDiagonalCross  |br| CubicStraightCrossSource  |br| CubicStraightCrossTarget | input       | The type of curve to compute (12 available: 6 quadratics and 6 cubics).                                     |
+-----------------+-------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+-------------------------------------------------------------------------------------------------------------+
| bezier edges    | Boolean                       | :const:`True`                                                                                                                                                                                                                                                                                                                                                                           | input       | If activated, set all edge shapes to Bézier curves.                                                         |
+-----------------+-------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+-------------------------------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Curve edges', graph)

  # set any input parameter value if needed
  # params['layout'] = ...
  # params['curve roundness'] = ...
  # params['curve type'] = ...
  # params['bezier edges'] = ...

  success = graph.applyAlgorithm('Curve edges', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Delaunay triangulation
^^^^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Performs a Delaunay triangulation, in considering the positions of the graph nodes as a set of points. The building of simplices (triangles in 2D or tetrahedrons in 3D) consists in adding edges between adjacent nodes.

Parameters
""""""""""

+----------------+---------+----------------+-------------+------------------------------------------------------------------------------------------------------+
| name           | type    | default        | direction   | description                                                                                          |
+================+=========+================+=============+======================================================================================================+
| simplices      | Boolean | :const:`False` | input       | If true, a subgraph will be added for each computed simplex (a triangle in 2d, a tetrahedron in 3d). |
+----------------+---------+----------------+-------------+------------------------------------------------------------------------------------------------------+
| original clone | Boolean | :const:`True`  | input       | If true, a clone subgraph named 'Original graph' will be first added.                                |
+----------------+---------+----------------+-------------+------------------------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Delaunay triangulation', graph)

  # set any input parameter value if needed
  # params['simplices'] = ...
  # params['original clone'] = ...

  success = graph.applyAlgorithm('Delaunay triangulation', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Directed Tree
^^^^^^^^^^^^^

Description
"""""""""""

Tests whether a graph is a directed tree or not.

Parameters
""""""""""

+--------+---------+-----------+-------------+------------------------------------+
| name   | type    | default   | direction   | description                        |
+========+=========+===========+=============+====================================+
| result | Boolean |           | output      | Whether the test succeeded or not. |
+--------+---------+-----------+-------------+------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Directed Tree', graph)

  success = graph.applyAlgorithm('Directed Tree', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Edge bundling
^^^^^^^^^^^^^

Description
"""""""""""

Edges routing algorithm, implementing the intuitive Edge Bundling technique published in : |br|  |bstart| Winding Roads: Routing edges into bundles |bend| , Antoine Lambert, Romain Bourqui and David Auber, Computer Graphics Forum special issue on 12th Eurographics/IEEE-VGTC Symposium on Visualization, pages 853-862 (2010).

Parameters
""""""""""

+-------------------+-----------------------------+----------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| name              | type                        | default        | direction   | description                                                                                                                                                                                                       |
+===================+=============================+================+=============+===================================================================================================================================================================================================================+
| layout            | :class:`tlp.LayoutProperty` | viewLayout     | input       | The input layout of the graph.                                                                                                                                                                                    |
+-------------------+-----------------------------+----------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| size              | :class:`tlp.SizeProperty`   | viewSize       | input       | The input node sizes.                                                                                                                                                                                             |
+-------------------+-----------------------------+----------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| grid_graph        | Boolean                     | :const:`False` | input       | If true, a subgraph corresponding to the grid used for routing edges will be added.                                                                                                                               |
+-------------------+-----------------------------+----------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| 3D_layout         | Boolean                     | :const:`False` | input       | If true, it is assumed that the input layout is in 3D and 3D edge bundling will be performed.                                                                                                                     |
+-------------------+-----------------------------+----------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| sphere_layout     | Boolean                     | :const:`False` | input       | If true, it is assumed that nodes have originally been laid out on a sphere surface.Edges will be routed along the sphere surface. The 3D_layout parameter needs also to be set to true for that feature to work. |
+-------------------+-----------------------------+----------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| long_edges        | floating point number       | 0.9            | input       | This parameter defines how long edges will be routed. A value less than 1.0 will promote paths outside dense regions of the input graph drawing.                                                                  |
+-------------------+-----------------------------+----------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| split_ratio       | floating point number       | 10             | input       | This parameter defines the granularity of the grid that will be generated for routing edges. The higher its value, the more precise the grid is.                                                                  |
+-------------------+-----------------------------+----------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| iterations        | unsigned integer            | 2              | input       | This parameter defines the number of iterations of the edge bundling process. The higher its value, the more edges will be bundled.                                                                               |
+-------------------+-----------------------------+----------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| max_thread        | unsigned integer            | 0              | input       | This parameter defines the number of threads to use for speeding up the edge bundling process. A value of 0 will use as much threads as processors on the host machine.                                           |
+-------------------+-----------------------------+----------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| edge_node_overlap | Boolean                     | :const:`False` | input       | If true, edges can be routed on original nodes.                                                                                                                                                                   |
+-------------------+-----------------------------+----------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Edge bundling', graph)

  # set any input parameter value if needed
  # params['layout'] = ...
  # params['size'] = ...
  # params['grid_graph'] = ...
  # params['3D_layout'] = ...
  # params['sphere_layout'] = ...
  # params['long_edges'] = ...
  # params['split_ratio'] = ...
  # params['iterations'] = ...
  # params['max_thread'] = ...
  # params['edge_node_overlap'] = ...

  success = graph.applyAlgorithm('Edge bundling', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Equal Value
^^^^^^^^^^^

Description
"""""""""""

Performs a graph clusterization grouping in the same cluster the nodes or edges having the same value for a given property.

Parameters
""""""""""

+-----------+--------------------------------+--------------------------------------------------------------------+-------------+------------------------------------------------------------------+
| name      | type                           | default                                                            | direction   | description                                                      |
+===========+================================+====================================================================+=============+==================================================================+
| Property  | :class:`tlp.PropertyInterface` | viewMetric                                                         | input       | Property used to partition the graph.                            |
+-----------+--------------------------------+--------------------------------------------------------------------+-------------+------------------------------------------------------------------+
| Type      | :class:`tlp.StringCollection`  | nodes |br| |br| Values for that parameter: |br| nodes  |br|  edges | input       | The type of graph elements to partition.                         |
+-----------+--------------------------------+--------------------------------------------------------------------+-------------+------------------------------------------------------------------+
| Connected | Boolean                        | :const:`False`                                                     | input       | If true, the resulting subgraphs are guaranteed to be connected. |
+-----------+--------------------------------+--------------------------------------------------------------------+-------------+------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Equal Value', graph)

  # set any input parameter value if needed
  # params['Property'] = ...
  # params['Type'] = ...
  # params['Connected'] = ...

  success = graph.applyAlgorithm('Equal Value', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Free Tree
^^^^^^^^^

Description
"""""""""""

Tests whether a graph is a free tree or not.

Parameters
""""""""""

+--------+---------+-----------+-------------+------------------------------------+
| name   | type    | default   | direction   | description                        |
+========+=========+===========+=============+====================================+
| result | Boolean |           | output      | Whether the test succeeded or not. |
+--------+---------+-----------+-------------+------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Free Tree', graph)

  success = graph.applyAlgorithm('Free Tree', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Graph
^^^^^

Description
"""""""""""

Tests whether the set of the selected elements of the current graph is a graph or not (no dangling edges).

Parameters
""""""""""

+-----------+------------------------------+---------------+-------------+-----------------------------------------------+
| name      | type                         | default       | direction   | description                                   |
+===========+==============================+===============+=============+===============================================+
| result    | Boolean                      |               | output      | Whether the test succeeded or not.            |
+-----------+------------------------------+---------------+-------------+-----------------------------------------------+
| selection | :class:`tlp.BooleanProperty` | viewSelection | input       | The property indicating the selected elements |
+-----------+------------------------------+---------------+-------------+-----------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Graph', graph)

  # set any input parameter value if needed
  # params['result'] = ...
  # params['selection'] = ...

  success = graph.applyAlgorithm('Graph', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Hierarchical
^^^^^^^^^^^^

Description
"""""""""""

This algorithm divides the graph in 2 different sub-graphs; the first one contains the nodes which have their viewMetric value below the mean, and, the other one, in which nodes have their viewMetric value above that mean value. Then, the algorithm is recursively applied to this subgraph (the one with the values above the threshold) until one sub-graph contains less than 10 nodes.

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Hierarchical', graph)

  success = graph.applyAlgorithm('Hierarchical', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Make Acyclic
^^^^^^^^^^^^

Description
"""""""""""

Makes a graph acyclic.

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Make Acyclic', graph)

  success = graph.applyAlgorithm('Make Acyclic', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Make Biconnected
^^^^^^^^^^^^^^^^

Description
"""""""""""

Makes a graph biconnected.

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Make Biconnected', graph)

  success = graph.applyAlgorithm('Make Biconnected', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Make Connected
^^^^^^^^^^^^^^

Description
"""""""""""

Makes a graph connected.

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Make Connected', graph)

  success = graph.applyAlgorithm('Make Connected', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Make Directed Tree
^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Makes a graph a directed tree.

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Make Directed Tree', graph)

  success = graph.applyAlgorithm('Make Directed Tree', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Make Planar Embedding
^^^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Makes the graph a planar embedding if it is planar.

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Make Planar Embedding', graph)

  success = graph.applyAlgorithm('Make Planar Embedding', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Make Simple
^^^^^^^^^^^

Description
"""""""""""

Makes a graph simple. |br| A simple graph is an undirected graph with no loops and no multiple edges.

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Make Simple', graph)

  success = graph.applyAlgorithm('Make Simple', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Maximal Cliques Enumeration
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Compute all maximal cliques (or maximal cliques whose size is above a given threshold) according to the Eppstein algorithm. See Eppstein, Loffler and Strash, Listing All Maximal Cliques in Sparse Graphs in Near-optimal Time, Experimental Algorithms, Springer, 2011

Parameters
""""""""""

+--------------+------------------+-----------+-------------+---------------------+
| name         | type             |   default | direction   | description         |
+==============+==================+===========+=============+=====================+
| minimum size | unsigned integer |         0 | input       | Clique minimum size |
+--------------+------------------+-----------+-------------+---------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Maximal Cliques Enumeration', graph)

  # set any input parameter value if needed
  # params['minimum size'] = ...

  success = graph.applyAlgorithm('Maximal Cliques Enumeration', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Outer Planar
^^^^^^^^^^^^

Description
"""""""""""

Tests whether a graph is outer planar or not.

Parameters
""""""""""

+--------+---------+-----------+-------------+------------------------------------+
| name   | type    | default   | direction   | description                        |
+========+=========+===========+=============+====================================+
| result | Boolean |           | output      | Whether the test succeeded or not. |
+--------+---------+-----------+-------------+------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Outer Planar', graph)

  success = graph.applyAlgorithm('Outer Planar', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Planar
^^^^^^

Description
"""""""""""

Tests whether a graph is planar or not.

Parameters
""""""""""

+--------+---------+-----------+-------------+------------------------------------+
| name   | type    | default   | direction   | description                        |
+========+=========+===========+=============+====================================+
| result | Boolean |           | output      | Whether the test succeeded or not. |
+--------+---------+-----------+-------------+------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Planar', graph)

  success = graph.applyAlgorithm('Planar', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Planar Embedding
^^^^^^^^^^^^^^^^

Description
"""""""""""

Tests whether a graph is a planar embedding or not.

Parameters
""""""""""

+--------+---------+-----------+-------------+------------------------------------+
| name   | type    | default   | direction   | description                        |
+========+=========+===========+=============+====================================+
| result | Boolean |           | output      | Whether the test succeeded or not. |
+--------+---------+-----------+-------------+------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Planar Embedding', graph)

  success = graph.applyAlgorithm('Planar Embedding', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Quotient Clustering
^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Computes a quotient sub-graph (meta-nodes pointing on sub-graphs) using an already existing sub-graphs hierarchy.

Parameters
""""""""""

+--------------------------+-------------------------------+-----------------------------------------------------------------------------------------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------+
| name                     | type                          | default                                                                                             | direction   | description                                                                                                                                            |
+==========================+===============================+=====================================================================================================+=============+========================================================================================================================================================+
| oriented                 | Boolean                       | :const:`True`                                                                                       | input       | If true, the graph is considered oriented.                                                                                                             |
+--------------------------+-------------------------------+-----------------------------------------------------------------------------------------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------+
| node function            | :class:`tlp.StringCollection` | none |br| |br| Values for that parameter: |br| none  |br|  average  |br|  sum  |br|  max  |br|  min | input       | Function used to compute a measure for a meta-node based on the values of its underlying nodes. If 'none', no value is computed.                       |
+--------------------------+-------------------------------+-----------------------------------------------------------------------------------------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------+
| edge function            | :class:`tlp.StringCollection` | none |br| |br| Values for that parameter: |br| none  |br|  average  |br|  sum  |br|  max  |br|  min | input       | Function used to compute a measure for a meta-edge based on the values of its underlying edges. If 'none', no value is computed.                       |
+--------------------------+-------------------------------+-----------------------------------------------------------------------------------------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------+
| meta-node label          | :class:`tlp.StringProperty`   |                                                                                                     | input       | Property used to label meta-nodes. An arbitrary underlying node is chosen and its associated value for the given property becomes the meta-node label. |
+--------------------------+-------------------------------+-----------------------------------------------------------------------------------------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------+
| use name of subgraph     | Boolean                       | :const:`False`                                                                                      | input       | If true, the meta-node label is the same as the name of the subgraph it represents.                                                                    |
+--------------------------+-------------------------------+-----------------------------------------------------------------------------------------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------+
| recursive                | Boolean                       | :const:`False`                                                                                      | input       | If true, the algorithm is applied along the entire hierarchy of subgraphs.                                                                             |
+--------------------------+-------------------------------+-----------------------------------------------------------------------------------------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------+
| layout quotient graph(s) | Boolean                       | :const:`False`                                                                                      | input       | If true, a force directed layout is computed for each quotient graph.                                                                                  |
+--------------------------+-------------------------------+-----------------------------------------------------------------------------------------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------+
| layout clusters          | Boolean                       | :const:`False`                                                                                      | input       | If true, a force directed layout is computed for each cluster graph.                                                                                   |
+--------------------------+-------------------------------+-----------------------------------------------------------------------------------------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------+
| edge cardinality         | Boolean                       | :const:`False`                                                                                      | input       | If true, the property edgeCardinality is created for each meta-edge of the quotient graph (and store the number of edges it represents).               |
+--------------------------+-------------------------------+-----------------------------------------------------------------------------------------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Quotient Clustering', graph)

  # set any input parameter value if needed
  # params['oriented'] = ...
  # params['node function'] = ...
  # params['edge function'] = ...
  # params['meta-node label'] = ...
  # params['use name of subgraph'] = ...
  # params['recursive'] = ...
  # params['layout quotient graph(s)'] = ...
  # params['layout clusters'] = ...
  # params['edge cardinality'] = ...

  success = graph.applyAlgorithm('Quotient Clustering', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Reverse edges
^^^^^^^^^^^^^

Description
"""""""""""

Reverse selected edges of the graph (or all if no selection property is given).

Parameters
""""""""""

+-----------+------------------------------+---------------+-------------+-----------------------------------------------------------------------------------------------+
| name      | type                         | default       | direction   | description                                                                                   |
+===========+==============================+===============+=============+===============================================================================================+
| selection | :class:`tlp.BooleanProperty` | viewSelection | input       | Only edges selected in this property (or all edges if no property is given) will be reversed. |
+-----------+------------------------------+---------------+-------------+-----------------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Reverse edges', graph)

  # set any input parameter value if needed
  # params['selection'] = ...

  success = graph.applyAlgorithm('Reverse edges', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Simple
^^^^^^

Description
"""""""""""

Tests whether a graph is simple or not. |br| A simple graph is an undirected graph with no loops and no multiple edges.

Parameters
""""""""""

+--------+---------+-----------+-------------+------------------------------------+
| name   | type    | default   | direction   | description                        |
+========+=========+===========+=============+====================================+
| result | Boolean |           | output      | Whether the test succeeded or not. |
+--------+---------+-----------+-------------+------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Simple', graph)

  success = graph.applyAlgorithm('Simple', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Squarified Tree Map Helper
^^^^^^^^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Enables to easily configure a treemap layout visualisation for a tree.
As the treemap layout is different from classical node link diagram representation, some
visual properties setup has to be done in order to get an aesthetic visualization of it in Tulip.
This plugin takes care of calling the 'Squarified Tree Map' layout algorithm and adjust
some visual properties to get a correct rendering of the treemap.

Parameters
""""""""""

+---------------+------------------------------+----------------------+-------------+----------------------------------------------------------------------------------------------------+
| name          | type                         | default              | direction   | description                                                                                        |
+===============+==============================+======================+=============+====================================================================================================+
| metric        | :class:`tlp.NumericProperty` |                      | input       | An optionnal metricused to estimate the size allocated to each node                                |
+---------------+------------------------------+----------------------+-------------+----------------------------------------------------------------------------------------------------+
| aspect ratio  | floating point number        | 1                    | input       | The aspect ratio (height/width) for the rectangle corresponding to the root node                   |
+---------------+------------------------------+----------------------+-------------+----------------------------------------------------------------------------------------------------+
| treemap type  | Boolean                      | :const:`False`       | input       | If true, use original Treemaps (B. Shneiderman) otherwise use Squarified Treemaps (J. J. van Wijk) |
+---------------+------------------------------+----------------------+-------------+----------------------------------------------------------------------------------------------------+
| border color  | :class:`tlp.Color`           | (255, 255, 255, 255) | input       | The border color that will be applied to all treemap nodes                                         |
+---------------+------------------------------+----------------------+-------------+----------------------------------------------------------------------------------------------------+
| layout        | :class:`tlp.LayoutProperty`  | viewLayout           | output      | The output treemap layout                                                                          |
+---------------+------------------------------+----------------------+-------------+----------------------------------------------------------------------------------------------------+
| sizes         | :class:`tlp.SizeProperty`    | viewSize             | output      | The output treemap sizes                                                                           |
+---------------+------------------------------+----------------------+-------------+----------------------------------------------------------------------------------------------------+
| shapes        | :class:`tlp.IntegerProperty` | viewShape            | output      | The output treemap shapes                                                                          |
+---------------+------------------------------+----------------------+-------------+----------------------------------------------------------------------------------------------------+
| colors        | :class:`tlp.ColorProperty`   | viewColor            | output      | The output treemap colors                                                                          |
+---------------+------------------------------+----------------------+-------------+----------------------------------------------------------------------------------------------------+
| border colors | :class:`tlp.ColorProperty`   | viewBorderColor      | output      | The output treemap border colors                                                                   |
+---------------+------------------------------+----------------------+-------------+----------------------------------------------------------------------------------------------------+
| border widths | :class:`tlp.DoubleProperty`  | viewBorderWidth      | output      | The output treemap border widths                                                                   |
+---------------+------------------------------+----------------------+-------------+----------------------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Squarified Tree Map Helper', graph)

  # set any input parameter value if needed
  # params['metric'] = ...
  # params['aspect ratio'] = ...
  # params['treemap type'] = ...
  # params['border color'] = ...
  # params['layout'] = ...
  # params['sizes'] = ...
  # params['shapes'] = ...
  # params['colors'] = ...
  # params['border colors'] = ...
  # params['border widths'] = ...

  success = graph.applyAlgorithm('Squarified Tree Map Helper', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Triconnected
^^^^^^^^^^^^

Description
"""""""""""

Tests whether a graph is triconnected or not.

Parameters
""""""""""

+--------+---------+-----------+-------------+------------------------------------+
| name   | type    | default   | direction   | description                        |
+========+=========+===========+=============+====================================+
| result | Boolean |           | output      | Whether the test succeeded or not. |
+--------+---------+-----------+-------------+------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Triconnected', graph)

  success = graph.applyAlgorithm('Triconnected', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Voronoi diagram
^^^^^^^^^^^^^^^

Description
"""""""""""

Performs a Voronoi decomposition, in considering the positions of the graph nodes as a set of points. These points define the seeds (or sites) of the voronoi cells. New nodes and edges are added to build the convex polygons defining the contours of these cells.

Parameters
""""""""""

+----------------+---------+----------------+-------------+----------------------------------------------------------------------------------------+
| name           | type    | default        | direction   | description                                                                            |
+================+=========+================+=============+========================================================================================+
| voronoi cells  | Boolean | :const:`False` | input       | If true, a subgraph will be added for each computed voronoi cell.                      |
+----------------+---------+----------------+-------------+----------------------------------------------------------------------------------------+
| connect        | Boolean | :const:`False` | input       | If true, existing graph nodes will be connected to the vertices of their voronoi cell. |
+----------------+---------+----------------+-------------+----------------------------------------------------------------------------------------+
| original clone | Boolean | :const:`True`  | input       | If true, a clone subgraph named 'Original graph' will be first added.                  |
+----------------+---------+----------------+-------------+----------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Voronoi diagram', graph)

  # set any input parameter value if needed
  # params['voronoi cells'] = ...
  # params['connect'] = ...
  # params['original clone'] = ...

  success = graph.applyAlgorithm('Voronoi diagram', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Coloring
--------

.. _colorpluginsdoc:

To call these plugins, you must use the :meth:`tlp.Graph.applyColorAlgorithm` method. See also for more details.

Alpha Mapping
^^^^^^^^^^^^^

Description
"""""""""""

Map metric values to alpha component of graph element colors.
In other words, it enables to compute the graph elements transparency according to the values
stored in a numeric property of a graph.

Parameters
""""""""""

+----------------+-------------------------------+------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| name           | type                          | default    | direction   | description                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
+================+===============================+============+=============+=======================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================+
| input property | :class:`tlp.NumericProperty`  | viewMetric | input       | The input numeric property from which to compute alpha mapping                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
+----------------+-------------------------------+------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| target         | :class:`tlp.StringCollection` | nodes      | input       | Whether alpha values are computed for nodes or edges                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  |
+----------------+-------------------------------+------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| type           | :class:`tlp.StringCollection` | linear     | input       | That parameter defines the type of alpha mapping to perform. For the linear case, the minimum value of  |br| the input numeric property is mapped to a minimum alpha value picked by the user, the maximum value is  |br| mapped to a maximum alpha value picked by the user, and a linear interpolation is used between both to  |br| compute the associated alpha of the graph element color. |br|   |br| For the logarithmic case, input numeric properties values are first mapped in the [1, +inf[ range. Then  |br| the log of each mapped value is computed and used to compute the associated alpha value of the graph  |br| element color trough a linear interpolation between 0 and the log of the mapped maximum value of graph elements. |br|  |br| If uniform, this is the same except for the interpolation: the values are sorted, numbered, and a linear  |br| interpolation is used on those numbers (in other words, only the order is taken into account, not the actual values). |
+----------------+-------------------------------+------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| min alpha      | unsigned integer              | 0          | input       | The minimum alpha value (between 0 and 255) to map on graph elements colors                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
+----------------+-------------------------------+------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| max alpha      | unsigned integer              | 255        | input       | The maximum alpha value (between 0 and 255) to map on graph elements colors                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
+----------------+-------------------------------+------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Alpha Mapping', graph)

  # set any input parameter value if needed
  # params['input property'] = ...
  # params['target'] = ...
  # params['type'] = ...
  # params['min alpha'] = ...
  # params['max alpha'] = ...

  # either create or get a color property from the graph to store the result of the algorithm
  resultColor = graph.getColorProperty('resultColor')
  success = graph.applyColorAlgorithm('Alpha Mapping', resultColor, params)

  # or store the result of the algorithm in the default Tulip color property named 'viewColor'
  success = graph.applyColorAlgorithm('Alpha Mapping', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Color Mapping
^^^^^^^^^^^^^

Description
"""""""""""

Colorizes the nodes or edges of a graph according to the values of a given property.

Parameters
""""""""""

+------------------------+--------------------------------+-------------------------------------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| name                   | type                           | default                                                                                                     | direction   | description                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
+========================+================================+=============================================================================================================+=============+===================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================+
| type                   | :class:`tlp.StringCollection`  | linear |br| |br| Values for that parameter: |br| linear  |br|  uniform  |br|  enumerated  |br|  logarithmic | input       | If linear, logarithmic or uniform, the input property must be a  |bstart| numeric |bend|  property. For the linear case, the minimum value is mapped to one end of the color scale, the maximum value is mapped to the other end, and a linear interpolation is used between both to compute the associated color. For the logarithmic case, graph elements values are first mapped in the [1, +inf[ range. Then the log of each mapped value is computed and used to compute the associated color of the graph element trough a linear interpolation between 0 and the log of the mapped maximum value of graph elements. |br| If uniform, this is the same except for the interpolation: the values are sorted, numbered, and a linear interpolation is used on those numbers(in other words, only the order is taken into account, not the actual values). |br| Finally, if enumerated, the input property can be of  |bstart| any type |bend| . Each possible value is mapped to a distinct color without any specific order. |
+------------------------+--------------------------------+-------------------------------------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| input property         | :class:`tlp.PropertyInterface` | viewMetric                                                                                                  | input       | This property is used to get the values affected to graph items.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  |
+------------------------+--------------------------------+-------------------------------------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| target                 | :class:`tlp.StringCollection`  | nodes |br| |br| Values for that parameter: |br| nodes  |br|  edges                                          | input       | Whether colors are computed for nodes or for edges.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
+------------------------+--------------------------------+-------------------------------------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| color scale            | :class:`tlp.ColorScale`        |                                                                                                             | input       | The color scale used to transform a node/edge property value into a color.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
+------------------------+--------------------------------+-------------------------------------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| override minimum value | Boolean                        | :const:`False`                                                                                              | input       | If true override the minimum value of the input property to keep coloring consistent across datasets.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             |
+------------------------+--------------------------------+-------------------------------------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| minimum value          | floating point number          |                                                                                                             | input       | That value will be used to override the minimum one of the input property.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
+------------------------+--------------------------------+-------------------------------------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| override maximum value | Boolean                        | :const:`False`                                                                                              | input       | If true override the maximum value of the input property to keep coloring consistent across datasets.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             |
+------------------------+--------------------------------+-------------------------------------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| maximum value          | floating point number          |                                                                                                             | input       | That value will be used to override the maximum one of the input property.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
+------------------------+--------------------------------+-------------------------------------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Color Mapping', graph)

  # set any input parameter value if needed
  # params['type'] = ...
  # params['input property'] = ...
  # params['target'] = ...
  # params['color scale'] = ...
  # params['override minimum value'] = ...
  # params['minimum value'] = ...
  # params['override maximum value'] = ...
  # params['maximum value'] = ...

  # either create or get a color property from the graph to store the result of the algorithm
  resultColor = graph.getColorProperty('resultColor')
  success = graph.applyColorAlgorithm('Color Mapping', resultColor, params)

  # or store the result of the algorithm in the default Tulip color property named 'viewColor'
  success = graph.applyColorAlgorithm('Color Mapping', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Export
------

.. _exportpluginsdoc:

To call these plugins, you must use the :func:`tlp.exportGraph` function.

CSV Export
^^^^^^^^^^

Description
"""""""""""

|pstart| Supported extensions: csv |pend|  |pstart| Exports the values of tulip graph properties associated to graph elements in a CSV file. |pend| 

Parameters
""""""""""

+---------------------------+-------------------------------+----------------+-------------+------------------------------------------------------------------------------------------------------------------------------------------------+
| name                      | type                          | default        | direction   | description                                                                                                                                    |
+===========================+===============================+================+=============+================================================================================================================================================+
| Type of elements          | :class:`tlp.StringCollection` | nodes          | input       | This parameter enables to choose the type of graph elements to export                                                                          |
+---------------------------+-------------------------------+----------------+-------------+------------------------------------------------------------------------------------------------------------------------------------------------+
| Export selection          | Boolean                       | :const:`False` | input       | This parameter indicates if only selected elements have to be exported                                                                         |
+---------------------------+-------------------------------+----------------+-------------+------------------------------------------------------------------------------------------------------------------------------------------------+
| Export selection property | :class:`tlp.BooleanProperty`  | viewSelection  | input       | This parameters enables to choose the property used for the selection                                                                          |
+---------------------------+-------------------------------+----------------+-------------+------------------------------------------------------------------------------------------------------------------------------------------------+
| Export id                 | Boolean                       | :const:`False` | input       | This parameter indicates if the id of graph elements has to be exported                                                                        |
+---------------------------+-------------------------------+----------------+-------------+------------------------------------------------------------------------------------------------------------------------------------------------+
| Export visual properties  | Boolean                       | :const:`False` | input       | This parameter indicates if the visual properties of Tulip will be exported                                                                    |
+---------------------------+-------------------------------+----------------+-------------+------------------------------------------------------------------------------------------------------------------------------------------------+
| Field separator           | :class:`tlp.StringCollection` | \              | input       | This parameter indicates the field separator (sequence of one or more characters used to specify the boundary between two consecutive fields). |
+---------------------------+-------------------------------+----------------+-------------+------------------------------------------------------------------------------------------------------------------------------------------------+
| Custom separator          | string                        | ;              | input       | This parameter allows to indicate a custom field separator. The 'Field separator' parameter must be set to 'Custom'                            |
+---------------------------+-------------------------------+----------------+-------------+------------------------------------------------------------------------------------------------------------------------------------------------+
| String delimiter          | :class:`tlp.StringCollection` | "              | input       | This parameter indicates the text delimiter (sequence of one or more characters used to specify the boundary of value of type text).           |
+---------------------------+-------------------------------+----------------+-------------+------------------------------------------------------------------------------------------------------------------------------------------------+
| Decimal mark              | :class:`tlp.StringCollection` | .              | input       | This parameter indicates the character used to separate the integer part from the fractional part of a number written in decimal form.         |
+---------------------------+-------------------------------+----------------+-------------+------------------------------------------------------------------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('CSV Export', graph)

  # set any input parameter value if needed
  # params['Type of elements'] = ...
  # params['Export selection'] = ...
  # params['Export selection property'] = ...
  # params['Export id'] = ...
  # params['Export visual properties'] = ...
  # params['Field separator'] = ...
  # params['Custom separator'] = ...
  # params['String delimiter'] = ...
  # params['Decimal mark'] = ...

  outputFile = '<path to a file>'
  success = tlp.exportGraph('CSV Export', graph, outputFile, params)
  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

GML Export
^^^^^^^^^^

Description
"""""""""""

|pstart| Supported extensions: gml |pend|  |pstart| Exports a Tulip graph in a file using the GML format (used by Graphlet). |br| See  |bstart| www.infosun.fmi.uni-passau.de/Graphlet/GML/ |bend|  for details. |pend| 

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('GML Export', graph)

  outputFile = '<path to a file>'
  success = tlp.exportGraph('GML Export', graph, outputFile, params)
  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

JSON Export
^^^^^^^^^^^

Description
"""""""""""

|pstart| Supported extensions: json |pend|  |pstart| Exports a graph in a file using the Tulip JSON format. |pend| 

Parameters
""""""""""

+----------------------+---------+----------------+-------------+-------------------------------------------------------------------+
| name                 | type    | default        | direction   | description                                                       |
+======================+=========+================+=============+===================================================================+
| Beautify JSON string | Boolean | :const:`False` | input       | If true, generate a JSON string with indentation and line breaks. |
+----------------------+---------+----------------+-------------+-------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('JSON Export', graph)

  # set any input parameter value if needed
  # params['Beautify JSON string'] = ...

  outputFile = '<path to a file>'
  success = tlp.exportGraph('JSON Export', graph, outputFile, params)
  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

SVG Export
^^^^^^^^^^

Description
"""""""""""

|pstart| Supported extensions: svg, svgz (compressed svg). |pend|  |pstart| Exports a graph visualization in a SVG formatted file. |pend| 

Parameters
""""""""""

+---------------------------------+--------------------+-------------------+-------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| name                            | type               | default           | direction   | description                                                                                                                                                                                                                                                                              |
+=================================+====================+===================+=============+==========================================================================================================================================================================================================================================================================================+
| Edge color interpolation        | Boolean            | :const:`False`    | input       | Indicates if edge color interpolation has to be used.                                                                                                                                                                                                                                    |
+---------------------------------+--------------------+-------------------+-------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| Edge size interpolation         | Boolean            | :const:`True`     | input       | Indicates if edge size interpolation has to be used.                                                                                                                                                                                                                                     |
+---------------------------------+--------------------+-------------------+-------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| Edge extremities                | Boolean            | :const:`False`    | input       | Indicates if edge extremities have to be exported.                                                                                                                                                                                                                                       |
+---------------------------------+--------------------+-------------------+-------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| Background color                | :class:`tlp.Color` | (255,255,255,255) | input       | Specifies the background color of the SVG file.                                                                                                                                                                                                                                          |
+---------------------------------+--------------------+-------------------+-------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| Makes SVG output human readable | Boolean            | :const:`True`     | input       | Adds line-breaks and indentation to empty sections between elements (ignorable whitespace). The main purpose of this parameter is to split the data into several lines, and to increase readability for a human reader. Be careful, this adds a large amount of data to the output file. |
+---------------------------------+--------------------+-------------------+-------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| Export node labels              | Boolean            | :const:`True`     | input       | Specifies if node labels have to be exported.                                                                                                                                                                                                                                            |
+---------------------------------+--------------------+-------------------+-------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| Export edge labels              | Boolean            | :const:`False`    | input       | Specifies if edge labels have to be exported.                                                                                                                                                                                                                                            |
+---------------------------------+--------------------+-------------------+-------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| Export metanode labels          | Boolean            | :const:`False`    | input       | Specifies if node and edge labels inside metanodes have to be exported.                                                                                                                                                                                                                  |
+---------------------------------+--------------------+-------------------+-------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| Use Web Open Font Format v2     | Boolean            | :const:`False`    | input       | Uses Web Open Font Format version 2 (woff2) to reduce generated file length. This format is supported in almost all recent Internet browsers.                                                                                                                                            |
+---------------------------------+--------------------+-------------------+-------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('SVG Export', graph)

  # set any input parameter value if needed
  # params['Edge color interpolation'] = ...
  # params['Edge size interpolation'] = ...
  # params['Edge extremities'] = ...
  # params['Background color'] = ...
  # params['Makes SVG output human readable'] = ...
  # params['Export node labels'] = ...
  # params['Export edge labels'] = ...
  # params['Export metanode labels'] = ...
  # params['Use Web Open Font Format v2'] = ...

  outputFile = '<path to a file>'
  success = tlp.exportGraph('SVG Export', graph, outputFile, params)
  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

TLP Export
^^^^^^^^^^

Description
"""""""""""

|pstart| Supported extensions: tlp, tlpz (compressed), tlp.gz (compressed) |pend|  |pstart| Exports a graph in a file using the TLP format (Tulip Software Graph Format). |br| See  |bstart| http://tulip.labri.fr->Framework->TLP File Format |bend|  for more details. |pend| 

Parameters
""""""""""

+----------------+--------+-----------------------------------+-------------+-----------------------------------+
| name           | type   | default                           | direction   | description                       |
+================+========+===================================+=============+===================================+
| name           | string |                                   | input       | Name of the graph being exported. |
+----------------+--------+-----------------------------------+-------------+-----------------------------------+
| author         | string |                                   | input       | Authors                           |
+----------------+--------+-----------------------------------+-------------+-----------------------------------+
| text::comments | string | This file was generated by Tulip. | input       | Description of the graph.         |
+----------------+--------+-----------------------------------+-------------+-----------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('TLP Export', graph)

  # set any input parameter value if needed
  # params['name'] = ...
  # params['author'] = ...
  # params['text::comments'] = ...

  outputFile = '<path to a file>'
  success = tlp.exportGraph('TLP Export', graph, outputFile, params)
  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

TLPB Export
^^^^^^^^^^^

Description
"""""""""""

|pstart| Supported extensions: tlpb, tlpbz (compressed), tlpb.gz (compressed) |pend|  |pstart| Exports a graph in a file using the Tulip binary format.

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('TLPB Export', graph)

  outputFile = '<path to a file>'
  success = tlp.exportGraph('TLPB Export', graph, outputFile, params)
  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Import
------

.. _importpluginsdoc:

To call these plugins, you must use the :func:`tlp.importGraph` function.

Adjacency Matrix
^^^^^^^^^^^^^^^^

Description
"""""""""""

Imports a graph from a file coding an adjacency matrix. |br| File format: |br| The input format of this plugin is an ascii file where each line represents a row of the matrix.In each row, cells must be separated by a space. |br| Let M(i,j) be a cell of the matrix : |br|      - if i==j we define the value of a node. |br|      - if i!=j  we define a directed edge between node[i] and node[j] |br| If M(i,j) is real value (0, .0, -1, -1.0), it is stored in the viewMetric property of the graph. |br| If M(i,j) is a string, it is stored in the viewLabel property of the graph. |br| Use & to set the viewMetric and viewLabel properties of a node or edge in the same time. |br| If M(i,j) == @ an edge will be created without value |br| If M(i,j) == # no edge will be created between node[i] and node[j] |br| EXAMPLE 1 : |br| A |br| # B |br| # # C |br| Defines a graph with 3 nodes (with labels A B C) and without edge. |br| EXAMPLE 2 : |br| A |br| @ B |br| @ @ C |br| Defines a simple complete graph with 3 nodes (with labels A B C) and no label (or value) on its edges |br| EXAMPLE 3 : |br| A # E & 5 |br| @ B |br| # @ C |br| Defines a graph with 3 nodes and 3 edges, the edge between A and C is named E and has the value 5

Parameters
""""""""""

+----------+---------------+-----------+-------------+------------------------------------------------------------+
| name     | type          | default   | direction   | description                                                |
+==========+===============+===========+=============+============================================================+
| filename | file pathname |           | input       | This parameter defines the pathname of the file to import. |
+----------+---------------+-----------+-------------+------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  params = tlp.getDefaultPluginParameters('Adjacency Matrix')

  # set any input parameter value if needed
  # params['filename'] = ...

  graph = tlp.importGraph('Adjacency Matrix', params)
  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Attract And Introduce Model
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Randomly generates a graph using the Attract and Introduce Model described in |br| J. H. Fowlera, C. T. Dawesa, N. A. Christakisb. |br|  |bstart| Model of genetic variation in human social networks. |bend|  |br| PNAS 106 (6): 1720-1724, 2009.

Parameters
""""""""""

+--------+-----------------------+-----------+-------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| name   | type                  |   default | direction   | description                                                                                                                                                                                                                                                                                                                           |
+========+=======================+===========+=============+=======================================================================================================================================================================================================================================================================================================================================+
| nodes  | unsigned integer      |     750   | input       | This parameter defines the amount of nodes used to build the graph.                                                                                                                                                                                                                                                                   |
+--------+-----------------------+-----------+-------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| edges  | unsigned integer      |    3150   | input       | This parameter defines the amount of edges used to build the graph.                                                                                                                                                                                                                                                                   |
+--------+-----------------------+-----------+-------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| alpha  | floating point number |       0.9 | input       | This parameter defines the alpha parameter between [0,1]. This one is a percentage and describes the distribution of attractiveness; the model suggests about 1 - alpha of the individuals have very low attractiveness whereas the remaining alpha are approximately evenly distributed between low, medium, and high attractiveness |
+--------+-----------------------+-----------+-------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| beta   | floating point number |       0.3 | input       | This parameter defines the beta parameter between [0,1]. This parameter indicates the probability a person will have the desire to introduce someone.                                                                                                                                                                                 |
+--------+-----------------------+-----------+-------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  params = tlp.getDefaultPluginParameters('Attract And Introduce Model')

  # set any input parameter value if needed
  # params['nodes'] = ...
  # params['edges'] = ...
  # params['alpha'] = ...
  # params['beta'] = ...

  graph = tlp.importGraph('Attract And Introduce Model', params)
  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

BibTeX
^^^^^^

Description
"""""""""""

|pstart| Supported extensions: bib |pend|  |pstart| Import a new graph from a BibTeX formatted file. |pend| 

Parameters
""""""""""

+-----------------+-------------------------------+-----------+-------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| name            | type                          | default   | direction   | description                                                                                                                                                                                                                                                                                                            |
+=================+===============================+===========+=============+========================================================================================================================================================================================================================================================================================================================+
| filename        | file pathname                 |           | input       | This parameter indicates the pathname of the file(.bib) to import.                                                                                                                                                                                                                                                     |
+-----------------+-------------------------------+-----------+-------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| Nodes to import | :class:`tlp.StringCollection` | Authors   | input       | The type of nodes to create: Authors  |istart| (Create nodes for authors only, publications are represented as edges between authors) |iend|  |br| Authors and Publications  |istart| (Create nodes for both authors and publications) |iend|  |br| Publications  |istart| (Create nodes for publications only) |iend| |
+-----------------+-------------------------------+-----------+-------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  params = tlp.getDefaultPluginParameters('BibTeX')

  # set any input parameter value if needed
  # params['filename'] = ...
  # params['Nodes to import'] = ...

  graph = tlp.importGraph('BibTeX', params)
  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Bollobas et al. Model
^^^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Randomly generates a scale-free graph using the model described in |br| B. Bollobas, O.M Riordan, J. Spencer and G. Tusnady. |br|  |bstart| The Degree Sequence of a Scale-Free Random Graph Process. |bend|  |br| RSA: Random Structures & Algorithms, 18, 279 (2001)

Parameters
""""""""""

+----------------+------------------+-----------+-------------+--------------------------------------------------------------------------------+
| name           | type             |   default | direction   | description                                                                    |
+================+==================+===========+=============+================================================================================+
| nodes          | unsigned integer |      2000 | input       | This parameter defines the amount of nodes used to build the scale-free graph. |
+----------------+------------------+-----------+-------------+--------------------------------------------------------------------------------+
| minimum degree | unsigned integer |         4 | input       | Minimum degree.                                                                |
+----------------+------------------+-----------+-------------+--------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  params = tlp.getDefaultPluginParameters('Bollobas et al. Model')

  # set any input parameter value if needed
  # params['nodes'] = ...
  # params['minimum degree'] = ...

  graph = tlp.importGraph('Bollobas et al. Model', params)
  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Bu Wang Zhou Model
^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Randomly generates a scale-free graph unsing the model described in |br| Shouliang Bu, Bing-Hong Wang, Tao Zhou. |br|  |bstart| Gaining scale-free and high clustering complex networks. |bend|  |br| Physica A, 374, 864--868, 2007.

Parameters
""""""""""

+----------------+------------------+-----------+-------------+------------------------------------------+
| name           | type             |   default | direction   | description                              |
+================+==================+===========+=============+==========================================+
| nodes          | unsigned integer |       200 | input       | Number of nodes.                         |
+----------------+------------------+-----------+-------------+------------------------------------------+
| types of nodes | unsigned integer |         3 | input       | Number of node types.                    |
+----------------+------------------+-----------+-------------+------------------------------------------+
| m              | unsigned integer |         2 | input       | Number of edges added for each new node. |
+----------------+------------------+-----------+-------------+------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  params = tlp.getDefaultPluginParameters('Bu Wang Zhou Model')

  # set any input parameter value if needed
  # params['nodes'] = ...
  # params['types of nodes'] = ...
  # params['m'] = ...

  graph = tlp.importGraph('Bu Wang Zhou Model', params)
  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

CMake dependencies graph
^^^^^^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Import the targets dependencies graph of a CMake project

Parameters
""""""""""

+--------------------------+--------------------+-----------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| name                     | type               | default   | direction   | description                                                                                                                                                       |
+==========================+====================+===========+=============+===================================================================================================================================================================+
| CMake project source dir | directory pathname |           | input       | The root source directory of the CMake project                                                                                                                    |
+--------------------------+--------------------+-----------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| CMake executable         | file pathname      | cmake     | input       | Optional parameter in order to provide the path to the CMake executable. |br| By default CMake executable path is assumed to be in your PATH environment variable |
+--------------------------+--------------------+-----------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| CMake parameters         | string             |           | input       | Optionnal parameter for providing some parameters to CMake in order to correctly configure the project                                                            |
+--------------------------+--------------------+-----------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  params = tlp.getDefaultPluginParameters('CMake dependencies graph')

  # set any input parameter value if needed
  # params['CMake project source dir'] = ...
  # params['CMake executable'] = ...
  # params['CMake parameters'] = ...

  graph = tlp.importGraph('CMake dependencies graph', params)
  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Catanzaro and al. Model
^^^^^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Randomly generates a graph using the model described in |br| Michele Catanzaro, Guido Caldarelli, and Luciano Pietronero. |br|  |bstart| Assortative model for social networks. |bend|  |br| Physical Review E (Statistical, Nonlinear, and Soft Matter Physics), 70(3), (2004).

Parameters
""""""""""

+--------+-----------------------+-----------+-------------+----------------------------------------------------------------+
| name   | type                  |   default | direction   | description                                                    |
+========+=======================+===========+=============+================================================================+
| nodes  | unsigned integer      |     300   | input       | Number of nodes.                                               |
+--------+-----------------------+-----------+-------------+----------------------------------------------------------------+
| m      | unsigned integer      |       5   | input       | Number of nodes added at each time step.                       |
+--------+-----------------------+-----------+-------------+----------------------------------------------------------------+
| p      | floating point number |       0.5 | input       | p defines the probality a new node is wired to an existing one |
+--------+-----------------------+-----------+-------------+----------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  params = tlp.getDefaultPluginParameters('Catanzaro and al. Model')

  # set any input parameter value if needed
  # params['nodes'] = ...
  # params['m'] = ...
  # params['p'] = ...

  graph = tlp.importGraph('Catanzaro and al. Model', params)
  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Complete General Graph
^^^^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Imports a new complete graph.

Parameters
""""""""""

+------------+------------------+---------------+-------------+---------------------------------------------------------------------------------------------------------+
| name       | type             | default       | direction   | description                                                                                             |
+============+==================+===============+=============+=========================================================================================================+
| nodes      | unsigned integer | 5             | input       | Number of nodes in the final graph.                                                                     |
+------------+------------------+---------------+-------------+---------------------------------------------------------------------------------------------------------+
| undirected | Boolean          | :const:`True` | input       | If true, the generated graph is undirected. If false, two edges are created between each pair of nodes. |
+------------+------------------+---------------+-------------+---------------------------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  params = tlp.getDefaultPluginParameters('Complete General Graph')

  # set any input parameter value if needed
  # params['nodes'] = ...
  # params['undirected'] = ...

  graph = tlp.importGraph('Complete General Graph', params)
  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Complete Tree
^^^^^^^^^^^^^

Description
"""""""""""

Imports a new complete tree.

Parameters
""""""""""

+-------------+------------------+----------------+-------------+-----------------------------------------------------------------------------+
| name        | type             | default        | direction   | description                                                                 |
+=============+==================+================+=============+=============================================================================+
| depth       | unsigned integer | 5              | input       | Depth of the tree.                                                          |
+-------------+------------------+----------------+-------------+-----------------------------------------------------------------------------+
| degree      | unsigned integer | 2              | input       | The tree's degree.                                                          |
+-------------+------------------+----------------+-------------+-----------------------------------------------------------------------------+
| tree layout | Boolean          | :const:`False` | input       | If true, the generated tree is drawn with the 'Tree Leaf' layout algorithm. |
+-------------+------------------+----------------+-------------+-----------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  params = tlp.getDefaultPluginParameters('Complete Tree')

  # set any input parameter value if needed
  # params['depth'] = ...
  # params['degree'] = ...
  # params['tree layout'] = ...

  graph = tlp.importGraph('Complete Tree', params)
  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Empty graph
^^^^^^^^^^^

Description
"""""""""""

A no-op plugin to import empty graphs

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  params = tlp.getDefaultPluginParameters('Empty graph')

  graph = tlp.importGraph('Empty graph', params)
  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Erdős-Rényi Random Graph
^^^^^^^^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Import a randomly generated graph following the Erdős-Rényi model. Given a positive integer n and a probability value in [0,1], define the graph G(n,p) to be the undirected graph on n vertices whose edges are chosen as follows: For all pairs of vertices v,w there is an edge (v,w) with probability p.

Parameters
""""""""""

+-------------+-----------------------+----------------+-------------+-------------------------------------------------------------------------------------------------+
| name        | type                  | default        | direction   | description                                                                                     |
+=============+=======================+================+=============+=================================================================================================+
| nodes       | unsigned integer      | 50             | input       | Number of nodes in the final graph.                                                             |
+-------------+-----------------------+----------------+-------------+-------------------------------------------------------------------------------------------------+
| probability | floating point number | 0.5            | input       | Probability of having an edge between each pair of vertices in the graph.                       |
+-------------+-----------------------+----------------+-------------+-------------------------------------------------------------------------------------------------+
| self loop   | Boolean               | :const:`False` | input       | Generate self loops (an edge with source and target on the same node) with the same probability |
+-------------+-----------------------+----------------+-------------+-------------------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  params = tlp.getDefaultPluginParameters('Erdős-Rényi Random Graph')

  # set any input parameter value if needed
  # params['nodes'] = ...
  # params['probability'] = ...
  # params['self loop'] = ...

  graph = tlp.importGraph('Erdős-Rényi Random Graph', params)
  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

File System Directory
^^^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Imports a tree representation of a file system directory.

Parameters
""""""""""

+----------------------+--------------------+----------------------+-------------+--------------------------------------------------------------------------------+
| name                 | type               | default              | direction   | description                                                                    |
+======================+====================+======================+=============+================================================================================+
| directory            | directory pathname |                      | input       | The directory to scan recursively.                                             |
+----------------------+--------------------+----------------------+-------------+--------------------------------------------------------------------------------+
| include hidden files | Boolean            | :const:`True`        | input       | If true, also include hidden files.                                            |
+----------------------+--------------------+----------------------+-------------+--------------------------------------------------------------------------------+
| follow symlinks      | Boolean            | :const:`True`        | input       | If true, follow symlinks on Unix (including Mac OS X) or .lnk file on Windows. |
+----------------------+--------------------+----------------------+-------------+--------------------------------------------------------------------------------+
| icons                | Boolean            | :const:`True`        | input       | If true, set icons as node shapes according to file mime types.                |
+----------------------+--------------------+----------------------+-------------+--------------------------------------------------------------------------------+
| tree layout          | Boolean            | :const:`True`        | input       | If true, apply the 'Bubble Tree' layout algorithm on the imported graph.       |
+----------------------+--------------------+----------------------+-------------+--------------------------------------------------------------------------------+
| directory color      | :class:`tlp.Color` | (255, 255, 127, 255) | input       | This parameter indicates the color used to display directories.                |
+----------------------+--------------------+----------------------+-------------+--------------------------------------------------------------------------------+
| other color          | :class:`tlp.Color` | (85, 170, 255, 255)  | input       | This parameter indicates the color used to display other files.                |
+----------------------+--------------------+----------------------+-------------+--------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  params = tlp.getDefaultPluginParameters('File System Directory')

  # set any input parameter value if needed
  # params['directory'] = ...
  # params['include hidden files'] = ...
  # params['follow symlinks'] = ...
  # params['icons'] = ...
  # params['tree layout'] = ...
  # params['directory color'] = ...
  # params['other color'] = ...

  graph = tlp.importGraph('File System Directory', params)
  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Fu and Liao Model
^^^^^^^^^^^^^^^^^

Description
"""""""""""

Randomly generates a scale-free graph using |br| Peihua Fu and Kun Liao. |br|  |bstart| An evolving scale-free network with large clustering coefficient. |bend|  |br| In ICARCV, pp. 1-4. IEEE, (2006).

Parameters
""""""""""

+--------+-----------------------+-----------+-------------+------------------------------------------+
| name   | type                  |   default | direction   | description                              |
+========+=======================+===========+=============+==========================================+
| nodes  | unsigned integer      |     300   | input       | Number of nodes.                         |
+--------+-----------------------+-----------+-------------+------------------------------------------+
| m      | unsigned integer      |       5   | input       | Number of nodes added at each time step. |
+--------+-----------------------+-----------+-------------+------------------------------------------+
| delta  | floating point number |       0.5 | input       | Delta coefficient must belong to [0, 1]  |
+--------+-----------------------+-----------+-------------+------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  params = tlp.getDefaultPluginParameters('Fu and Liao Model')

  # set any input parameter value if needed
  # params['nodes'] = ...
  # params['m'] = ...
  # params['delta'] = ...

  graph = tlp.importGraph('Fu and Liao Model', params)
  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

GEXF
^^^^

Description
"""""""""""

|pstart| Supported extensions: gexf |pend|  |pstart| Imports a new graph from a file in the GEXF input format |br| as it is described in the XML Schema 1.2 draft (http://gexf.net/format/schema.html). |br| Dynamic mode is not yet supported. |pend| 

Parameters
""""""""""

+--------------+---------------+----------------+-------------+-----------------------------------------------------------------+
| name         | type          | default        | direction   | description                                                     |
+==============+===============+================+=============+=================================================================+
| filename     | file pathname |                | input       | This parameter defines the pathname of the GEXF file to import. |
+--------------+---------------+----------------+-------------+-----------------------------------------------------------------+
| Curved edges | Boolean       | :const:`False` | input       | Indicates if Bézier curves should be used to draw the edges.    |
+--------------+---------------+----------------+-------------+-----------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  params = tlp.getDefaultPluginParameters('GEXF')

  # set any input parameter value if needed
  # params['filename'] = ...
  # params['Curved edges'] = ...

  graph = tlp.importGraph('GEXF', params)
  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

GML
^^^

Description
"""""""""""

|pstart| Supported extension: gml |pend|  |pstart| Imports a new graph from a file (.gml) in the GML input format (used by Graphlet). |br| See  |bstart| www.infosun.fmi.uni-passau.de/Graphlet/GML/ |bend|  for details. |pend| 

Parameters
""""""""""

+----------+---------------+-----------+-------------+-----------------------------------------+
| name     | type          | default   | direction   | description                             |
+==========+===============+===========+=============+=========================================+
| filename | file pathname |           | input       | The pathname of the GML file to import. |
+----------+---------------+-----------+-------------+-----------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  params = tlp.getDefaultPluginParameters('GML')

  # set any input parameter value if needed
  # params['filename'] = ...

  graph = tlp.importGraph('GML', params)
  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

GraphML
^^^^^^^

Description
"""""""""""

|pstart| Supported extension: graphml |pend|  |pstart| Imports a graph from a file in the GraphML format (http://graphml.graphdrawing.org/).
GraphML is a comprehensive and easy-to-use file format for graphs.
It consists of a language core to describe the structural properties 
of a graph and a flexible extension mechanism to add application-specific data. |pend| 

Parameters
""""""""""

+----------+---------------+-----------+-------------+----------------------------+
| name     | type          | default   | direction   | description                |
+==========+===============+===========+=============+============================+
| filename | file pathname |           | input       | the GraphML file to import |
+----------+---------------+-----------+-------------+----------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  params = tlp.getDefaultPluginParameters('GraphML')

  # set any input parameter value if needed
  # params['filename'] = ...

  graph = tlp.importGraph('GraphML', params)
  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Grid
^^^^

Description
"""""""""""

Imports a new grid structured graph.

Parameters
""""""""""

+------------------------+-------------------------------+-----------------------------------------------------------------+-------------+----------------------------------------------------------------------------------------------------------------------+
| name                   | type                          | default                                                         | direction   | description                                                                                                          |
+========================+===============================+=================================================================+=============+======================================================================================================================+
| width                  | unsigned integer              | 10                                                              | input       | Grid node width.                                                                                                     |
+------------------------+-------------------------------+-----------------------------------------------------------------+-------------+----------------------------------------------------------------------------------------------------------------------+
| height                 | unsigned integer              | 10                                                              | input       | Grid node height.                                                                                                    |
+------------------------+-------------------------------+-----------------------------------------------------------------+-------------+----------------------------------------------------------------------------------------------------------------------+
| connectivity           | :class:`tlp.StringCollection` | 4 |br| |br| Values for that parameter: |br| 4  |br|  6  |br|  8 | input       | Connectivity number of each node.                                                                                    |
+------------------------+-------------------------------+-----------------------------------------------------------------+-------------+----------------------------------------------------------------------------------------------------------------------+
| oppositeNodesConnected | Boolean                       | :const:`False`                                                  | input       | If true, opposite nodes on each side of the grid are connected. In a 4 connectivity the resulting object is a torus. |
+------------------------+-------------------------------+-----------------------------------------------------------------+-------------+----------------------------------------------------------------------------------------------------------------------+
| spacing                | floating point number         | 1.0                                                             | input       | Spacing between nodes.                                                                                               |
+------------------------+-------------------------------+-----------------------------------------------------------------+-------------+----------------------------------------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  params = tlp.getDefaultPluginParameters('Grid')

  # set any input parameter value if needed
  # params['width'] = ...
  # params['height'] = ...
  # params['connectivity'] = ...
  # params['oppositeNodesConnected'] = ...
  # params['spacing'] = ...

  graph = tlp.importGraph('Grid', params)
  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Grid Approximation
^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Imports a new grid approximation graph.

Parameters
""""""""""

+-----------+------------------+----------------+-------------+-------------------------------------------------------------------+
| name      | type             | default        | direction   | description                                                       |
+===========+==================+================+=============+===================================================================+
| nodes     | unsigned integer | 200            | input       | Number of nodes in the final graph.                               |
+-----------+------------------+----------------+-------------+-------------------------------------------------------------------+
| degree    | unsigned integer | 10             | input       | Average degree of the nodes in the final graph.                   |
+-----------+------------------+----------------+-------------+-------------------------------------------------------------------+
| long edge | Boolean          | :const:`False` | input       | If true, long distance edges are added in the grid approximation. |
+-----------+------------------+----------------+-------------+-------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  params = tlp.getDefaultPluginParameters('Grid Approximation')

  # set any input parameter value if needed
  # params['nodes'] = ...
  # params['degree'] = ...
  # params['long edge'] = ...

  graph = tlp.importGraph('Grid Approximation', params)
  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Guillaume Latapy Model
^^^^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Randomly generates a small word graph using the model described in |br| J.-L. Guillaume and M. Latapy. |br|  |bstart| Bipartite graphs as models of complex networks. |bend|  |br| In Workshop on Combinatorial and Algorithmic Aspects of Networking (CAAN), LNCS, volume 1, 2004.

Parameters
""""""""""

+--------+------------------+-----------+-------------+---------------------------------------------------------------------------------+
| name   | type             |   default | direction   | description                                                                     |
+========+==================+===========+=============+=================================================================================+
| nodes  | unsigned integer |       200 | input       | This parameter defines the amount of nodes used to build the small-world graph. |
+--------+------------------+-----------+-------------+---------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  params = tlp.getDefaultPluginParameters('Guillaume Latapy Model')

  # set any input parameter value if needed
  # params['nodes'] = ...

  graph = tlp.importGraph('Guillaume Latapy Model', params)
  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Holme and Kim Model
^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Randomly generates a scale-free graph using the model described in |br| Petter Holme and Beom Jun Kim. |br|  |bstart| Growing scale-free networks with tunable clustering. |bend|  |br| Physical Review E, 65, 026107, (2002).

Parameters
""""""""""

+--------+-----------------------+-----------+-------------+--------------------------------------------------------------+
| name   | type                  |   default | direction   | description                                                  |
+========+=======================+===========+=============+==============================================================+
| nodes  | unsigned integer      |     300   | input       | Number of nodes.                                             |
+--------+-----------------------+-----------+-------------+--------------------------------------------------------------+
| m      | unsigned integer      |       5   | input       | Number of edges added at each time step.                     |
+--------+-----------------------+-----------+-------------+--------------------------------------------------------------+
| p      | floating point number |       0.5 | input       | Probability of adding a triangle after adding a random edge. |
+--------+-----------------------+-----------+-------------+--------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  params = tlp.getDefaultPluginParameters('Holme and Kim Model')

  # set any input parameter value if needed
  # params['nodes'] = ...
  # params['m'] = ...
  # params['p'] = ...

  graph = tlp.importGraph('Holme and Kim Model', params)
  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

JSON Import
^^^^^^^^^^^

Description
"""""""""""

|pstart| Supported extensions: json |pend|  |pstart| Imports a graph recorded in a file using the Tulip JSON format. |pend| 

Parameters
""""""""""

+----------+---------------+-----------+-------------+----------------------------------------------+
| name     | type          | default   | direction   | description                                  |
+==========+===============+===========+=============+==============================================+
| filename | file pathname |           | input       | The pathname of the TLP JSON file to import. |
+----------+---------------+-----------+-------------+----------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  params = tlp.getDefaultPluginParameters('JSON Import')

  # set any input parameter value if needed
  # params['filename'] = ...

  graph = tlp.importGraph('JSON Import', params)
  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Klemm Eguiluz Model
^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Randomly generates a small world graph using the model described in |br| Konstantin Klemm and Victor M. Eguiluz. |br|  |bstart| Growing Scale-Free Networks with Small World Behavior. |bend|  |br| Physical Review E, 65, 057102,(2002).

Parameters
""""""""""

+--------+-----------------------+-----------+-------------+-----------------------------------------------------------------------------------------+
| name   | type                  |   default | direction   | description                                                                             |
+========+=======================+===========+=============+=========================================================================================+
| nodes  | unsigned integer      |     200   | input       | Number of nodes.                                                                        |
+--------+-----------------------+-----------+-------------+-----------------------------------------------------------------------------------------+
| m      | unsigned integer      |      10   | input       | Number of activated nodes.                                                              |
+--------+-----------------------+-----------+-------------+-----------------------------------------------------------------------------------------+
| mu     | floating point number |       0.5 | input       | Probability to connect a node to a random other node |br| instead of an activated node. |
+--------+-----------------------+-----------+-------------+-----------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  params = tlp.getDefaultPluginParameters('Klemm Eguiluz Model')

  # set any input parameter value if needed
  # params['nodes'] = ...
  # params['m'] = ...
  # params['mu'] = ...

  graph = tlp.importGraph('Klemm Eguiluz Model', params)
  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Liu et al. model
^^^^^^^^^^^^^^^^

Description
"""""""""""

Randomly generates a small world graph using the model described in |br| J.-G. Liu, Y.-Z. Dang, and Z. tuo Wang. |br|  |bstart| Multistage random growing small-world networks with power-law degree distribution. |bend|  |br| Chinese Phys. Lett., 23(3):746, Oct. 31 2005.

Parameters
""""""""""

+--------+------------------+-----------+-------------+------------------+
| name   | type             |   default | direction   | description      |
+========+==================+===========+=============+==================+
| nodes  | unsigned integer |       300 | input       | Number of nodes. |
+--------+------------------+-----------+-------------+------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  params = tlp.getDefaultPluginParameters('Liu et al. model')

  # set any input parameter value if needed
  # params['nodes'] = ...

  graph = tlp.importGraph('Liu et al. model', params)
  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Npm package dependencies graph
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

 Import the packages dependencies graph from a npm package.
 Be sure to have called 'npm install' in the package directory first
 in order to get the complete dependencies graph.
 

Parameters
""""""""""

+-----------------+--------------------+-----------+-------------+---------------------------------------+
| name            | type               | default   | direction   | description                           |
+=================+====================+===========+=============+=======================================+
| npm package dir | directory pathname |           | input       | The root directory of the npm package |
+-----------------+--------------------+-----------+-------------+---------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  params = tlp.getDefaultPluginParameters('Npm package dependencies graph')

  # set any input parameter value if needed
  # params['npm package dir'] = ...

  graph = tlp.importGraph('Npm package dependencies graph', params)
  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Pajek
^^^^^

Description
"""""""""""

|pstart| Supported extensions: net, paj |pend|  |pstart| Imports a new graph from a file (.net) in Pajek input format |br| as it is described in the Pajek manual ( |bstart| http://pajek.imfm.si/lib/exe/fetch.php?media=dl:pajekman203.pdf |bend| ) |br| from the Pajek wiki page  |bstart| http://pajek.imfm.si/doku.php?id=download |bend| . |br| Warning: the description of the edges with Matrix (adjacency lists) |br| is not yet supported. |pend| 

Parameters
""""""""""

+----------+---------------+-----------+-------------+-----------------------------------------------------------------------------------+
| name     | type          | default   | direction   | description                                                                       |
+==========+===============+===========+=============+===================================================================================+
| filename | file pathname |           | input       | This parameter indicates the pathname of the Pajek file (.net or .paj) to import. |
+----------+---------------+-----------+-------------+-----------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  params = tlp.getDefaultPluginParameters('Pajek')

  # set any input parameter value if needed
  # params['filename'] = ...

  graph = tlp.importGraph('Pajek', params)
  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Planar Graph
^^^^^^^^^^^^

Description
"""""""""""

Imports a new randomly generated planar graph.

Parameters
""""""""""

+--------+------------------+-----------+-------------+-------------------------------------+
| name   | type             |   default | direction   | description                         |
+========+==================+===========+=============+=====================================+
| nodes  | unsigned integer |        30 | input       | Number of nodes in the final graph. |
+--------+------------------+-----------+-------------+-------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  params = tlp.getDefaultPluginParameters('Planar Graph')

  # set any input parameter value if needed
  # params['nodes'] = ...

  graph = tlp.importGraph('Planar Graph', params)
  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Random General Graph
^^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Imports a new randomly generated graph.

Parameters
""""""""""

+--------+------------------+-----------+-------------+-------------------------------------+
| name   | type             |   default | direction   | description                         |
+========+==================+===========+=============+=====================================+
| nodes  | unsigned integer |       500 | input       | Number of nodes in the final graph. |
+--------+------------------+-----------+-------------+-------------------------------------+
| edges  | unsigned integer |      1000 | input       | Number of edges in the final graph. |
+--------+------------------+-----------+-------------+-------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  params = tlp.getDefaultPluginParameters('Random General Graph')

  # set any input parameter value if needed
  # params['nodes'] = ...
  # params['edges'] = ...

  graph = tlp.importGraph('Random General Graph', params)
  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Random General Tree
^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Imports a new randomly generated tree.

Parameters
""""""""""

+-----------------------+------------------+----------------+-------------+-----------------------------------------------------------------------------+
| name                  | type             | default        | direction   | description                                                                 |
+=======================+==================+================+=============+=============================================================================+
| Minimum size          | unsigned integer | 10             | input       | Minimal number of nodes in the tree.                                        |
+-----------------------+------------------+----------------+-------------+-----------------------------------------------------------------------------+
| Maximum size          | unsigned integer | 100            | input       | Maximal number of nodes in the tree.                                        |
+-----------------------+------------------+----------------+-------------+-----------------------------------------------------------------------------+
| Maximal node's degree | unsigned integer | 5              | input       | Maximal degree of the nodes.                                                |
+-----------------------+------------------+----------------+-------------+-----------------------------------------------------------------------------+
| tree layout           | Boolean          | :const:`False` | input       | If true, the generated tree is drawn with the 'Tree Leaf' layout algorithm. |
+-----------------------+------------------+----------------+-------------+-----------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  params = tlp.getDefaultPluginParameters('Random General Tree')

  # set any input parameter value if needed
  # params['Minimum size'] = ...
  # params['Maximum size'] = ...
  # params['Maximal node's degree'] = ...
  # params['tree layout'] = ...

  graph = tlp.importGraph('Random General Tree', params)
  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Random Simple Graph
^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Imports a new randomly generated simple graph.

Parameters
""""""""""

+--------+------------------+-----------+-------------+-------------------------------------+
| name   | type             |   default | direction   | description                         |
+========+==================+===========+=============+=====================================+
| nodes  | unsigned integer |       500 | input       | Number of nodes in the final graph. |
+--------+------------------+-----------+-------------+-------------------------------------+
| edges  | unsigned integer |      1000 | input       | Number of edges in the final graph. |
+--------+------------------+-----------+-------------+-------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  params = tlp.getDefaultPluginParameters('Random Simple Graph')

  # set any input parameter value if needed
  # params['nodes'] = ...
  # params['edges'] = ...

  graph = tlp.importGraph('Random Simple Graph', params)
  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

TLP Import
^^^^^^^^^^

Description
"""""""""""

|pstart| Supported extensions: tlp, tlpz (compressed), tlp.gz (compressed) |pend|  |pstart| Imports a graph recorded in a file using the TLP format (Tulip Software Graph Format). |br| See  |bstart| http://tulip.labri.fr->Framework->TLP File Format |bend|  for description. |br| Note: When using the Tulip graphical user interface, |br| choosing  |bstart| File->Import->TLP |bend|  menu item is the same as using  |bstart| File->Open |bend|  menu item. |pend| 

Parameters
""""""""""

+----------+---------------+-----------+-------------+-----------------------------------------+
| name     | type          | default   | direction   | description                             |
+==========+===============+===========+=============+=========================================+
| filename | file pathname |           | input       | The pathname of the TLP file to import. |
+----------+---------------+-----------+-------------+-----------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  params = tlp.getDefaultPluginParameters('TLP Import')

  # set any input parameter value if needed
  # params['filename'] = ...

  graph = tlp.importGraph('TLP Import', params)
  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

TLPB Import
^^^^^^^^^^^

Description
"""""""""""

|pstart| Supported extensions: tlpb, tlpb.gz (compressed), tlpbz (compressed) |pend|  |pstart| Imports a graph recorded in a file using the Tulip binary format. |pend| 

Parameters
""""""""""

+----------+---------------+-----------+-------------+------------------------------------------+
| name     | type          | default   | direction   | description                              |
+==========+===============+===========+=============+==========================================+
| filename | file pathname |           | input       | The pathname of the TLPB file to import. |
+----------+---------------+-----------+-------------+------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  params = tlp.getDefaultPluginParameters('TLPB Import')

  # set any input parameter value if needed
  # params['filename'] = ...

  graph = tlp.importGraph('TLPB Import', params)
  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

UCINET
^^^^^^

Description
"""""""""""

|pstart| Supported extensions: txt |pend|  |pstart| Imports a new graph from a text file in UCINET DL input format |br| as it is described in the UCINET reference manual ( |bstart| http://www.analytictech.com/ucinet/documentation/reference.rtf |bend|  |pend| )

Parameters
""""""""""

+----------------+---------------+-----------+-------------+----------------------------------------------------------------------------------+
| name           | type          | default   | direction   | description                                                                      |
+================+===============+===========+=============+==================================================================================+
| filename       | file pathname |           | input       | This parameter indicates the pathname of the file in UCINET DL format to import. |
+----------------+---------------+-----------+-------------+----------------------------------------------------------------------------------+
| Default metric | string        | weight    | input       | This parameter indicates the name of the default metric.                         |
+----------------+---------------+-----------+-------------+----------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  params = tlp.getDefaultPluginParameters('UCINET')

  # set any input parameter value if needed
  # params['filename'] = ...
  # params['Default metric'] = ...

  graph = tlp.importGraph('UCINET', params)
  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Uniform Random Binary Tree
^^^^^^^^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Imports a new randomly generated uniform binary tree.

Parameters
""""""""""

+--------------+------------------+----------------+-------------+-----------------------------------------------------------------------------+
| name         | type             | default        | direction   | description                                                                 |
+==============+==================+================+=============+=============================================================================+
| Minimum size | unsigned integer | 50             | input       | Minimal number of nodes in the tree.                                        |
+--------------+------------------+----------------+-------------+-----------------------------------------------------------------------------+
| Maximum size | unsigned integer | 60             | input       | Maximal number of nodes in the tree.                                        |
+--------------+------------------+----------------+-------------+-----------------------------------------------------------------------------+
| tree layout  | Boolean          | :const:`False` | input       | If true, the generated tree is drawn with the 'Tree Leaf' layout algorithm. |
+--------------+------------------+----------------+-------------+-----------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  params = tlp.getDefaultPluginParameters('Uniform Random Binary Tree')

  # set any input parameter value if needed
  # params['Minimum size'] = ...
  # params['Maximum size'] = ...
  # params['tree layout'] = ...

  graph = tlp.importGraph('Uniform Random Binary Tree', params)
  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Wang and Rong Model
^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Randomly generates a small-world graph using the model described in |br| Jianwei Wang and Lili Rong. |br|  |bstart| Evolving small-world networks based on the modified BA model. |bend|  |br| International Conference on Computer Science and Information Technology, 0, 143-146, (2008).

Parameters
""""""""""

+--------+------------------+-----------+-------------+------------------------------------------+
| name   | type             |   default | direction   | description                              |
+========+==================+===========+=============+==========================================+
| nodes  | unsigned integer |       300 | input       | Number of nodes.                         |
+--------+------------------+-----------+-------------+------------------------------------------+
| m0     | unsigned integer |         5 | input       | Number of nodes in the initial ring.     |
+--------+------------------+-----------+-------------+------------------------------------------+
| m      | unsigned integer |         5 | input       | Number of nodes added at each time step. |
+--------+------------------+-----------+-------------+------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  params = tlp.getDefaultPluginParameters('Wang and Rong Model')

  # set any input parameter value if needed
  # params['nodes'] = ...
  # params['m0'] = ...
  # params['m'] = ...

  graph = tlp.importGraph('Wang and Rong Model', params)
  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Wang et al. Model
^^^^^^^^^^^^^^^^^

Description
"""""""""""

Randomly generates a small world graph using the model described in |br| L.Wang, F. Du, H. P. Dai, and Y. X. Sun. |br|  |bstart| Random pseudofractal scale-free networks with small-world effect. |bend|  |br| The European Physical Journal B - Condensed Matter and Complex Systems, 53, 361-366, (2006).

Parameters
""""""""""

+--------+------------------+-----------+-------------+------------------+
| name   | type             |   default | direction   | description      |
+========+==================+===========+=============+==================+
| nodes  | unsigned integer |       300 | input       | Number of nodes. |
+--------+------------------+-----------+-------------+------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  params = tlp.getDefaultPluginParameters('Wang et al. Model')

  # set any input parameter value if needed
  # params['nodes'] = ...

  graph = tlp.importGraph('Wang et al. Model', params)
  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Watts Strotgatz Model
^^^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Randomly generates a small world graph using the model described in |br| D. J. Watts and S. H. Strogatz. |br|  |bstart| Collective dynamics of small-world networks. |bend|  |br| Nature 393, 440 (1998).

Parameters
""""""""""

+----------------+-----------------------+----------------+-------------+---------------------------------------------------------------------------------+
| name           | type                  | default        | direction   | description                                                                     |
+================+=======================+================+=============+=================================================================================+
| nodes          | unsigned integer      | 200            | input       | This parameter defines the amount of nodes used to build the scale-free graph.  |
+----------------+-----------------------+----------------+-------------+---------------------------------------------------------------------------------+
| k              | unsigned integer      | 3              | input       | Number of edges added to each node in the inital ring lattice.                  |
+----------------+-----------------------+----------------+-------------+---------------------------------------------------------------------------------+
| p              | floating point number | 0.02           | input       | Probability in [0,1] to rewire an edge.                                         |
+----------------+-----------------------+----------------+-------------+---------------------------------------------------------------------------------+
| original model | Boolean               | :const:`False` | input       | Use the original model: k describes the degree of each vertex (k > 1 and even). |
+----------------+-----------------------+----------------+-------------+---------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  params = tlp.getDefaultPluginParameters('Watts Strotgatz Model')

  # set any input parameter value if needed
  # params['nodes'] = ...
  # params['k'] = ...
  # params['p'] = ...
  # params['original model'] = ...

  graph = tlp.importGraph('Watts Strotgatz Model', params)
  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Web Site
^^^^^^^^

Description
"""""""""""

Imports a new graph from Web site structure (one node per page).

Parameters
""""""""""

+-------------------+--------------------+--------------------+-------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| name              | type               | default            | direction   | description                                                                                                                                                      |
+===================+====================+====================+=============+==================================================================================================================================================================+
| server            | string             | www.labri.fr       | input       | This parameter defines the web server that you want to inspect. No need for http:// at the beginning; http protocol is always assumed. No need for / at the end. |
+-------------------+--------------------+--------------------+-------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| web page          | string             |                    | input       | This parameter defines the first web page to visit. No need for / at the beginning.                                                                              |
+-------------------+--------------------+--------------------+-------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| max size          | integer            | 1000               | input       | This parameter defines the maximum number of nodes (different pages) allowed in the extracted graph.                                                             |
+-------------------+--------------------+--------------------+-------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| non http links    | Boolean            | :const:`False`     | input       | This parameter indicates if non http links (https, ftp, mailto...) have to be extracted.                                                                         |
+-------------------+--------------------+--------------------+-------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| other server      | Boolean            | :const:`False`     | input       | This parameter indicates if links or redirection to other server pages have to be followed.                                                                      |
+-------------------+--------------------+--------------------+-------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| compute layout    | Boolean            | :const:`True`      | input       | This parameter indicates if a layout of the extracted graph has to be computed.                                                                                  |
+-------------------+--------------------+--------------------+-------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| page color        | :class:`tlp.Color` | (240, 0, 120, 128) | input       | This parameter indicates the color used to display nodes.                                                                                                        |
+-------------------+--------------------+--------------------+-------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| link color        | :class:`tlp.Color` | (96,96,191,128)    | input       | This parameter indicates the color used to display links.                                                                                                        |
+-------------------+--------------------+--------------------+-------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| redirection color | :class:`tlp.Color` | (191,175,96,128)   | input       | This parameter indicates the color used to display redirections.                                                                                                 |
+-------------------+--------------------+--------------------+-------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  params = tlp.getDefaultPluginParameters('Web Site')

  # set any input parameter value if needed
  # params['server'] = ...
  # params['web page'] = ...
  # params['max size'] = ...
  # params['non http links'] = ...
  # params['other server'] = ...
  # params['compute layout'] = ...
  # params['page color'] = ...
  # params['link color'] = ...
  # params['redirection color'] = ...

  graph = tlp.importGraph('Web Site', params)
  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

graphviz
^^^^^^^^

Description
"""""""""""

|pstart| Supported extensions: dot |pend|  |pstart| Imports a new graph from a file in the dot input format. |pend| 

Parameters
""""""""""

+----------+---------------+-----------+-------------+-------------------------+
| name     | type          | default   | direction   | description             |
+==========+===============+===========+=============+=========================+
| filename | file pathname |           | input       | The dot file to import. |
+----------+---------------+-----------+-------------+-------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  params = tlp.getDefaultPluginParameters('graphviz')

  # set any input parameter value if needed
  # params['filename'] = ...

  graph = tlp.importGraph('graphviz', params)
  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Labeling
--------

.. _stringpluginsdoc:

To call these plugins, you must use the :meth:`tlp.Graph.applyStringAlgorithm` method. See also :ref:`Calling a property algorithm on a graph <callPropertyAlgorithm>` for more details.

To labels
^^^^^^^^^

Description
"""""""""""

Maps the labels of the graph elements onto the values of a given property.

Parameters
""""""""""

+-----------+--------------------------------+---------------+-------------+----------------------------------------------+
| name      | type                           | default       | direction   | description                                  |
+===========+================================+===============+=============+==============================================+
| input     | :class:`tlp.PropertyInterface` | viewMetric    | input       | Property to stringify values on labels.      |
+-----------+--------------------------------+---------------+-------------+----------------------------------------------+
| selection | :class:`tlp.BooleanProperty`   |               | input       | Set of elements for which to set the labels. |
+-----------+--------------------------------+---------------+-------------+----------------------------------------------+
| nodes     | Boolean                        | :const:`True` | input       | Sets labels on nodes.                        |
+-----------+--------------------------------+---------------+-------------+----------------------------------------------+
| edges     | Boolean                        | :const:`True` | input       | Set labels on edges.                         |
+-----------+--------------------------------+---------------+-------------+----------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('To labels', graph)

  # set any input parameter value if needed
  # params['input'] = ...
  # params['selection'] = ...
  # params['nodes'] = ...
  # params['edges'] = ...

  # either create or get a string property from the graph to store the result of the algorithm
  resultString = graph.getStringProperty('resultString')
  success = graph.applyStringAlgorithm('To labels', resultString, params)

  # or store the result of the algorithm in the default Tulip string property named 'viewLabel'
  success = graph.applyStringAlgorithm('To labels', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Layout
------

.. _layoutpluginsdoc:

To call these plugins, you must use the :meth:`tlp.Graph.applyLayoutAlgorithm` method. See also :ref:`Calling a property algorithm on a graph <callPropertyAlgorithm>` for more details.

3-Connected (Tutte)
^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Implements the Tutte layout for 3-Connected graph algorithm first published as: |br|  |bstart| How to Draw a Graph |bend| , W.T. Tutte, Proc. London Math. Soc. pages 743--768 (1963).

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('3-Connected (Tutte)', graph)

  # either create or get a layout property from the graph to store the result of the algorithm
  resultLayout = graph.getLayoutProperty('resultLayout')
  success = graph.applyLayoutAlgorithm('3-Connected (Tutte)', resultLayout, params)

  # or store the result of the algorithm in the default Tulip layout property named 'viewLayout'
  success = graph.applyLayoutAlgorithm('3-Connected (Tutte)', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Balloon (OGDF)
^^^^^^^^^^^^^^

Description
"""""""""""

Computes a radial (balloon) layout based on a spanning tree. |br| The algorithm is partially based on the paper  |bstart| On Balloon Drawings of Rooted Trees |bend|  by Lin and Yen and on  |bstart| Interacting with Huge Hierarchies: Beyond Cone Trees |bend|  by Carriere and Kazman. 

Parameters
""""""""""

+-------------+---------+----------------+-------------+-------------------------------------------------------------------------+
| name        | type    | default        | direction   | description                                                             |
+=============+=========+================+=============+=========================================================================+
| Even angles | Boolean | :const:`False` | input       | Subtrees may be assigned even angles or angles depending on their size. |
+-------------+---------+----------------+-------------+-------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Balloon (OGDF)', graph)

  # set any input parameter value if needed
  # params['Even angles'] = ...

  # either create or get a layout property from the graph to store the result of the algorithm
  resultLayout = graph.getLayoutProperty('resultLayout')
  success = graph.applyLayoutAlgorithm('Balloon (OGDF)', resultLayout, params)

  # or store the result of the algorithm in the default Tulip layout property named 'viewLayout'
  success = graph.applyLayoutAlgorithm('Balloon (OGDF)', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Bertault (OGDF)
^^^^^^^^^^^^^^^

Description
"""""""""""

Computes a force directed layout (Bertault Layout) for preserving the planar embedding in the graph.

Parameters
""""""""""

+-----------+-----------------------+----------------+-------------+-------------------------------------------------------------------------------------------------------+
| name      | type                  | default        | direction   | description                                                                                           |
+===========+=======================+================+=============+=======================================================================================================+
| impred    | Boolean               | :const:`False` | input       | Sets impred option.                                                                                   |
+-----------+-----------------------+----------------+-------------+-------------------------------------------------------------------------------------------------------+
| iterno    | integer               | 20             | input       | The number of iterations. If 0, the number of iterations will be set as 10 times the number of nodes. |
+-----------+-----------------------+----------------+-------------+-------------------------------------------------------------------------------------------------------+
| reqlength | floating point number | 0.0            | input       | The required edge length.                                                                             |
+-----------+-----------------------+----------------+-------------+-------------------------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Bertault (OGDF)', graph)

  # set any input parameter value if needed
  # params['impred'] = ...
  # params['iterno'] = ...
  # params['reqlength'] = ...

  # either create or get a layout property from the graph to store the result of the algorithm
  resultLayout = graph.getLayoutProperty('resultLayout')
  success = graph.applyLayoutAlgorithm('Bertault (OGDF)', resultLayout, params)

  # or store the result of the algorithm in the default Tulip layout property named 'viewLayout'
  success = graph.applyLayoutAlgorithm('Bertault (OGDF)', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Bubble Tree
^^^^^^^^^^^

Description
"""""""""""

Implement the bubble tree drawing algorithm first published as: |br|  |bstart| Bubble Tree Drawing Algorithm |bend| , D. Auber and S. Grivet and J-P Domenger and Guy Melancon, ICCVG, pages 633-641 (2004).

Parameters
""""""""""

+------------+---------------------------+---------------+-------------+-------------------------------------------------------------------------------------------------------------------------------+
| name       | type                      | default       | direction   | description                                                                                                                   |
+============+===========================+===============+=============+===============================================================================================================================+
| node size  | :class:`tlp.SizeProperty` | viewSize      | input       | This parameter defines the property used for node sizes.                                                                      |
+------------+---------------------------+---------------+-------------+-------------------------------------------------------------------------------------------------------------------------------+
| complexity | Boolean                   | :const:`True` | input       | This parameter enables to choose the complexity of the algorithm.If true, the complexity is O(n.log(n)), if false it is O(n). |
+------------+---------------------------+---------------+-------------+-------------------------------------------------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Bubble Tree', graph)

  # set any input parameter value if needed
  # params['node size'] = ...
  # params['complexity'] = ...

  # either create or get a layout property from the graph to store the result of the algorithm
  resultLayout = graph.getLayoutProperty('resultLayout')
  success = graph.applyLayoutAlgorithm('Bubble Tree', resultLayout, params)

  # or store the result of the algorithm in the default Tulip layout property named 'viewLayout'
  success = graph.applyLayoutAlgorithm('Bubble Tree', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Circular
^^^^^^^^

Description
"""""""""""

Implements a circular layout that takes node size into account. |br| It manages size of nodes and use a standard dfs for ordering nodes or search the maximum length cycle.

Parameters
""""""""""

+--------------+---------------------------+----------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------+
| name         | type                      | default        | direction   | description                                                                                                                                           |
+==============+===========================+================+=============+=======================================================================================================================================================+
| node size    | :class:`tlp.SizeProperty` | viewSize       | input       | This parameter defines the property used for node sizes.                                                                                              |
+--------------+---------------------------+----------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------+
| search cycle | Boolean                   | :const:`False` | input       | If true, search first for the maximum length cycle (be careful, this problem is NP-Complete). If false, nodes are ordered using a depth first search. |
+--------------+---------------------------+----------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Circular', graph)

  # set any input parameter value if needed
  # params['node size'] = ...
  # params['search cycle'] = ...

  # either create or get a layout property from the graph to store the result of the algorithm
  resultLayout = graph.getLayoutProperty('resultLayout')
  success = graph.applyLayoutAlgorithm('Circular', resultLayout, params)

  # or store the result of the algorithm in the default Tulip layout property named 'viewLayout'
  success = graph.applyLayoutAlgorithm('Circular', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Circular (OGDF)
^^^^^^^^^^^^^^^

Description
"""""""""""

Implements a circular layout.

Parameters
""""""""""

+----------------+-----------------------+-----------+-------------+-------------------------------------------------------+
| name           | type                  |   default | direction   | description                                           |
+================+=======================+===========+=============+=======================================================+
| minDistCircle  | floating point number |        20 | input       | The minimal distance between nodes on a circle.       |
+----------------+-----------------------+-----------+-------------+-------------------------------------------------------+
| minDistLevel   | floating point number |        20 | input       | The minimal distance between father and child circle. |
+----------------+-----------------------+-----------+-------------+-------------------------------------------------------+
| minDistSibling | floating point number |        10 | input       | The minimal distance between circles on same level.   |
+----------------+-----------------------+-----------+-------------+-------------------------------------------------------+
| minDistCC      | floating point number |        20 | input       | The minimal distance between connected components.    |
+----------------+-----------------------+-----------+-------------+-------------------------------------------------------+
| pageRatio      | floating point number |         1 | input       | The page ratio used for packing connected components. |
+----------------+-----------------------+-----------+-------------+-------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Circular (OGDF)', graph)

  # set any input parameter value if needed
  # params['minDistCircle'] = ...
  # params['minDistLevel'] = ...
  # params['minDistSibling'] = ...
  # params['minDistCC'] = ...
  # params['pageRatio'] = ...

  # either create or get a layout property from the graph to store the result of the algorithm
  resultLayout = graph.getLayoutProperty('resultLayout')
  success = graph.applyLayoutAlgorithm('Circular (OGDF)', resultLayout, params)

  # or store the result of the algorithm in the default Tulip layout property named 'viewLayout'
  success = graph.applyLayoutAlgorithm('Circular (OGDF)', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Cone Tree
^^^^^^^^^

Description
"""""""""""

Implements an extension of the Cone tree layout algorithm first published as: |br|  |bstart| Interacting with Huge Hierarchies: Beyond Cone Trees  |bend| , A. FJ. Carriere and R. Kazman, InfoViz'95, IEEE Symposium on Information Visualization pages 74--78 (1995).

Parameters
""""""""""

+----------------------+-------------------------------+-------------------------------------------------------------------------------+-------------+--------------------------------------------------------------------------------------+
| name                 | type                          | default                                                                       | direction   | description                                                                          |
+======================+===============================+===============================================================================+=============+======================================================================================+
| node size            | :class:`tlp.SizeProperty`     | viewSize                                                                      | input       | This parameter defines the property used for node sizes.                             |
+----------------------+-------------------------------+-------------------------------------------------------------------------------+-------------+--------------------------------------------------------------------------------------+
| orientation          | :class:`tlp.StringCollection` | vertical |br| |br| Values for that parameter: |br| vertical  |br|  horizontal | input       | This parameter enables to choose the orientation of the drawing.                     |
+----------------------+-------------------------------+-------------------------------------------------------------------------------+-------------+--------------------------------------------------------------------------------------+
| space between levels | floating point number         | 1.0                                                                           | input       | This parameter enables to add extra spacing between the different levels of the tree |
+----------------------+-------------------------------+-------------------------------------------------------------------------------+-------------+--------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Cone Tree', graph)

  # set any input parameter value if needed
  # params['node size'] = ...
  # params['orientation'] = ...
  # params['space between levels'] = ...

  # either create or get a layout property from the graph to store the result of the algorithm
  resultLayout = graph.getLayoutProperty('resultLayout')
  success = graph.applyLayoutAlgorithm('Cone Tree', resultLayout, params)

  # or store the result of the algorithm in the default Tulip layout property named 'viewLayout'
  success = graph.applyLayoutAlgorithm('Cone Tree', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Connected Component Packing
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Implements a layout packing of the connected components of a graph. It builds a layout of the graph connected components so that they do not overlap and minimizes the lost space (packing).

Parameters
""""""""""

+-------------+-------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------------------------------+
| name        | type                          | default                                                                                                                                                     | direction   | description                                                                              |
+=============+===============================+=============================================================================================================================================================+=============+==========================================================================================+
| coordinates | :class:`tlp.LayoutProperty`   | viewLayout                                                                                                                                                  | input       | Input layout of nodes and edges.                                                         |
+-------------+-------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------------------------------+
| node size   | :class:`tlp.SizeProperty`     | viewSize                                                                                                                                                    | input       | This parameter defines the property used for node sizes.                                 |
+-------------+-------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------------------------------+
| rotation    | :class:`tlp.DoubleProperty`   | viewRotation                                                                                                                                                | input       | Input rotation of nodes around the z-axis.                                               |
+-------------+-------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------------------------------+
| complexity  | :class:`tlp.StringCollection` | auto |br| |br| Values for that parameter: |br| auto  |br|  n5  |br|  n4logn  |br|  n4  |br|  n3logn  |br|  n3  |br|  n2logn  |br|  n2  |br|  nlogn  |br|  n | input       | Complexity of the algorithm. |br|  n is the number of connected components in the graph. |
+-------------+-------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Connected Component Packing', graph)

  # set any input parameter value if needed
  # params['coordinates'] = ...
  # params['node size'] = ...
  # params['rotation'] = ...
  # params['complexity'] = ...

  # either create or get a layout property from the graph to store the result of the algorithm
  resultLayout = graph.getLayoutProperty('resultLayout')
  success = graph.applyLayoutAlgorithm('Connected Component Packing', resultLayout, params)

  # or store the result of the algorithm in the default Tulip layout property named 'viewLayout'
  success = graph.applyLayoutAlgorithm('Connected Component Packing', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Connected Component Packing (Polyomino)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Implements the connected component packing algorithm published as: |br|  |bstart| Disconnected Graph Layout and the Polyomino Packing Approach |bend| , Freivalds Karlis, Dogrusoz Ugur and Kikusts Paulis, Graph Drawing '01 Revised Papers from the 9th International Symposium on Graph Drawing.

Parameters
""""""""""

+-------------+-----------------------------+--------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| name        | type                        | default      | direction   | description                                                                                                                                                                                                 |
+=============+=============================+==============+=============+=============================================================================================================================================================================================================+
| coordinates | :class:`tlp.LayoutProperty` | viewLayout   | input       | Input layout of nodes and edges.                                                                                                                                                                            |
+-------------+-----------------------------+--------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| node size   | :class:`tlp.SizeProperty`   | viewSize     | input       | This parameter defines the property used for node sizes.                                                                                                                                                    |
+-------------+-----------------------------+--------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| rotation    | :class:`tlp.DoubleProperty` | viewRotation | input       | Input rotation of nodes on z-axis                                                                                                                                                                           |
+-------------+-----------------------------+--------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| margin      | unsigned integer            | 1            | input       | The minimum margin between each pair of nodes in the resulting packed layout.                                                                                                                               |
+-------------+-----------------------------+--------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| increment   | unsigned integer            | 1            | input       | The polyomino packing tries to find a place where the next polyomino will fit by following a square.If there is no place where the polyomino fits, the square gets bigger and every place gets tried again. |
+-------------+-----------------------------+--------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Connected Component Packing (Polyomino)', graph)

  # set any input parameter value if needed
  # params['coordinates'] = ...
  # params['node size'] = ...
  # params['rotation'] = ...
  # params['margin'] = ...
  # params['increment'] = ...

  # either create or get a layout property from the graph to store the result of the algorithm
  resultLayout = graph.getLayoutProperty('resultLayout')
  success = graph.applyLayoutAlgorithm('Connected Component Packing (Polyomino)', resultLayout, params)

  # or store the result of the algorithm in the default Tulip layout property named 'viewLayout'
  success = graph.applyLayoutAlgorithm('Connected Component Packing (Polyomino)', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Davidson Harel (OGDF)
^^^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Implements the Davidson-Harel layout algorithm which uses simulated annealing to find a layout of minimal energy. |br| Due to this approach, the algorithm can only handle graphs of rather limited size. |br| It is based on the following publication: |br|  |bstart| Drawing Graphs Nicely Using Simulated Annealing |bend| , Ron Davidson, David Harel,  ACM Transactions on Graphics 15(4), pp. 301-331, 1996.

Parameters
""""""""""

+-------------------------------+-------------------------------+------------------------------------------------------------------------------------------+-------------+-------------------------------------------------------+
| name                          | type                          | default                                                                                  | direction   | description                                           |
+===============================+===============================+==========================================================================================+=============+=======================================================+
| Settings                      | :class:`tlp.StringCollection` | Standard |br| |br| Values for that parameter: |br| Standard  |br|  Repulse  |br|  Planar | input       | Easy way to set fixed costs.                          |
+-------------------------------+-------------------------------+------------------------------------------------------------------------------------------+-------------+-------------------------------------------------------+
| Speed                         | :class:`tlp.StringCollection` | Fast |br| |br| Values for that parameter: |br| Fast  |br|  Medium  |br|  HQ              | input       | Easy way to set temperature and number of iterations. |
+-------------------------------+-------------------------------+------------------------------------------------------------------------------------------+-------------+-------------------------------------------------------+
| preferredEdgeLength           | floating point number         | 0.0                                                                                      | input       | The preferred edge length.                            |
+-------------------------------+-------------------------------+------------------------------------------------------------------------------------------+-------------+-------------------------------------------------------+
| preferredEdgeLengthMultiplier | floating point number         | 2.0                                                                                      | input       | The preferred edge length multiplier for attraction.  |
+-------------------------------+-------------------------------+------------------------------------------------------------------------------------------+-------------+-------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Davidson Harel (OGDF)', graph)

  # set any input parameter value if needed
  # params['Settings'] = ...
  # params['Speed'] = ...
  # params['preferredEdgeLength'] = ...
  # params['preferredEdgeLengthMultiplier'] = ...

  # either create or get a layout property from the graph to store the result of the algorithm
  resultLayout = graph.getLayoutProperty('resultLayout')
  success = graph.applyLayoutAlgorithm('Davidson Harel (OGDF)', resultLayout, params)

  # or store the result of the algorithm in the default Tulip layout property named 'viewLayout'
  success = graph.applyLayoutAlgorithm('Davidson Harel (OGDF)', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Dendrogram
^^^^^^^^^^

Description
"""""""""""

This is an implementation of a dendrogram, an extended implementation of a  |bstart| Bio representation |bend|  which includes variable orientation and variable node sizelayout.

Parameters
""""""""""

+---------------+-------------------------------+-----------------------------------------------------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------------------------+
| name          | type                          | default                                                                                                                     | direction   | description                                                                             |
+===============+===============================+=============================================================================================================================+=============+=========================================================================================+
| node size     | :class:`tlp.SizeProperty`     | viewSize                                                                                                                    | input       | This parameter defines the property used for node sizes.                                |
+---------------+-------------------------------+-----------------------------------------------------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------------------------+
| orientation   | :class:`tlp.StringCollection` | up to down |br| |br| Values for that parameter: |br| up to down  |br|  down to up  |br|  right to left  |br|  left to right | input       | Choose a desired orientation.                                                           |
+---------------+-------------------------------+-----------------------------------------------------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------------------------+
| layer spacing | floating point number         | 64.                                                                                                                         | input       | This parameter enables to set up the minimum space between two layers in the drawing.   |
+---------------+-------------------------------+-----------------------------------------------------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------------------------+
| node spacing  | floating point number         | 18.                                                                                                                         | input       | This parameter enables to set up the minimum space between two nodes in the same layer. |
+---------------+-------------------------------+-----------------------------------------------------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Dendrogram', graph)

  # set any input parameter value if needed
  # params['node size'] = ...
  # params['orientation'] = ...
  # params['layer spacing'] = ...
  # params['node spacing'] = ...

  # either create or get a layout property from the graph to store the result of the algorithm
  resultLayout = graph.getLayoutProperty('resultLayout')
  success = graph.applyLayoutAlgorithm('Dendrogram', resultLayout, params)

  # or store the result of the algorithm in the default Tulip layout property named 'viewLayout'
  success = graph.applyLayoutAlgorithm('Dendrogram', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Dominance (OGDF)
^^^^^^^^^^^^^^^^

Description
"""""""""""

Implements a simple upward drawing algorithm based on dominance drawings of st-digraphs.

Parameters
""""""""""

+-----------------------+---------+----------------+-------------+-------------------------------------------+
| name                  | type    | default        | direction   | description                               |
+=======================+=========+================+=============+===========================================+
| minimum grid distance | integer | 1              | input       | The minimum grid distance.                |
+-----------------------+---------+----------------+-------------+-------------------------------------------+
| transpose             | Boolean | :const:`False` | input       | If true, transpose the layout vertically. |
+-----------------------+---------+----------------+-------------+-------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Dominance (OGDF)', graph)

  # set any input parameter value if needed
  # params['minimum grid distance'] = ...
  # params['transpose'] = ...

  # either create or get a layout property from the graph to store the result of the algorithm
  resultLayout = graph.getLayoutProperty('resultLayout')
  success = graph.applyLayoutAlgorithm('Dominance (OGDF)', resultLayout, params)

  # or store the result of the algorithm in the default Tulip layout property named 'viewLayout'
  success = graph.applyLayoutAlgorithm('Dominance (OGDF)', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

FM^3 (OGDF)
^^^^^^^^^^^

Description
"""""""""""

Implements the FM³ layout algorithm by Hachul and Jünger. It is a multilevel, force-directed layout algorithm that can be applied to very large graphs.

Parameters
""""""""""

+---------------------------+-------------------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------------------------------------------------------------+
| name                      | type                          | default                                                                                                                                                                                                                                                                                                                                           | direction   | description                                                                                                            |
+===========================+===============================+===================================================================================================================================================================================================================================================================================================================================================+=============+========================================================================================================================+
| Edge Length Property      | :class:`tlp.NumericProperty`  | viewMetric                                                                                                                                                                                                                                                                                                                                        | input       | A numeric property containing unit edge length to use.                                                                 |
+---------------------------+-------------------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------------------------------------------------------------+
| Node Size                 | :class:`tlp.SizeProperty`     | viewSize                                                                                                                                                                                                                                                                                                                                          | input       | The node sizes.                                                                                                        |
+---------------------------+-------------------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------------------------------------------------------------+
| Unit edge length          | floating point number         | 10.0                                                                                                                                                                                                                                                                                                                                              | input       | The unit edge length.                                                                                                  |
+---------------------------+-------------------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------------------------------------------------------------+
| New initial placement     | Boolean                       | :const:`True`                                                                                                                                                                                                                                                                                                                                     | input       | Indicates the initial placement before running algorithm.                                                              |
+---------------------------+-------------------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------------------------------------------------------------+
| Fixed iterations          | integer                       | 30                                                                                                                                                                                                                                                                                                                                                | input       | The fixed number of iterations for the stop criterion.                                                                 |
+---------------------------+-------------------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------------------------------------------------------------+
| Threshold                 | floating point number         | 0.01                                                                                                                                                                                                                                                                                                                                              | input       | The threshold for the stop criterion.                                                                                  |
+---------------------------+-------------------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------------------------------------------------------------+
| Page Format               | :class:`tlp.StringCollection` | Square |br| |br| Values for that parameter: |br| Portrait  |istart| (A4 portrait page) |iend|  |br| Landscape  |istart| (A4 landscape page) |iend|  |br| Square  |istart| (Square format) |iend|                                                                                                                                                  | input       | Possible page formats.                                                                                                 |
+---------------------------+-------------------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------------------------------------------------------------+
| Quality vs Speed          | :class:`tlp.StringCollection` | BeautifulAndFast |br| |br| Values for that parameter: |br| GorgeousAndEfficient  |istart| (Best quality) |iend|  |br| BeautifulAndFast  |istart| (Medium quality and speed) |iend|  |br| NiceAndIncredibleSpeed  |istart| (Best speed |iend|                                                                                                      | input       | Trade-off between run-time and quality.                                                                                |
+---------------------------+-------------------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------------------------------------------------------------+
| Edge Length Measurement   | :class:`tlp.StringCollection` | BoundingCircle |br| |br| Values for that parameter: |br| Midpoint  |istart| (Measure from center point of edge end points) |iend|  |br| BoundingCircle  |istart| (Measure from border of circle surrounding edge end points) |iend|                                                                                                               | input       | Specifies how the length of an edge is measured.                                                                       |
+---------------------------+-------------------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------------------------------------------------------------+
| Allowed Positions         | :class:`tlp.StringCollection` | Integer |br| |br| Values for that parameter: |br| All |br|  Integer  |br|  Exponent                                                                                                                                                                                                                                                               | input       | Specifies which positions for a node are allowed.                                                                      |
+---------------------------+-------------------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------------------------------------------------------------+
| Tip Over                  | :class:`tlp.StringCollection` | NoGrowingRow |br| |br| Values for that parameter: |br| None |br|  NoGrowingRow |br|  Always                                                                                                                                                                                                                                                       | input       | Specifies in which case it is allowed to tip over drawings of connected components.                                    |
+---------------------------+-------------------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------------------------------------------------------------+
| Pre Sort                  | :class:`tlp.StringCollection` | DecreasingHeight |br| |br| Values for that parameter: |br| None  |istart| (Do not presort) |iend|  |br| DecreasingHeight  |istart| (Presort by decreasing height of components) |iend|  |br| DecreasingWidth  |istart| (Presort by decreasing width of components) |iend|                                                                         | input       | Specifies how connected components are sorted before the packing algorithm is applied.                                 |
+---------------------------+-------------------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------------------------------------------------------------+
| Galaxy Choice             | :class:`tlp.StringCollection` | NonUniformProbLowerMass |br| |br| Values for that parameter: |br| UniformProb |br| NonUniformProbLowerMass |br| NonUniformProbHigherMass                                                                                                                                                                                                          | input       | Specifies how sun nodes of galaxies are selected.                                                                      |
+---------------------------+-------------------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------------------------------------------------------------+
| Max Iter Change           | :class:`tlp.StringCollection` | LinearlyDecreasing |br| |br| Values for that parameter: |br| Constant  |br| LinearlyDecreasing  |br| RapidlyDecreasing                                                                                                                                                                                                                            | input       | Specifies how MaxIterations is changed in subsequent multilevels.                                                      |
+---------------------------+-------------------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------------------------------------------------------------+
| Initial Placement Mult    | :class:`tlp.StringCollection` | Advanced |br| |br| Values for that parameter: |br| Simple  |br|  Advanced                                                                                                                                                                                                                                                                         | input       | Specifies how the initial placement is generated.                                                                      |
+---------------------------+-------------------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------------------------------------------------------------+
| Force Model               | :class:`tlp.StringCollection` | New |br| |br| Values for that parameter: |br| FruchtermanReingold  |istart| (The force-model by Fruchterman, Reingold) |iend|  |br| Eades  |istart| (The force-model by Eades) |iend|  |br| New  |istart| (The new force-model) |iend|                                                                                                            | input       | Specifies the force-model.                                                                                             |
+---------------------------+-------------------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------------------------------------------------------------+
| Repulsive Force Method    | :class:`tlp.StringCollection` | NMM |br| |br| Values for that parameter: |br| Exact  |istart| (Exact calculation) |iend|  |br| GridApproximation  |istart| (Grid approximation) |iend|  |br| NMM  |istart| (Calculation as for new multipole method) |iend|                                                                                                                       | input       | Specifies how to calculate repulsive forces.                                                                           |
+---------------------------+-------------------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------------------------------------------------------------+
| Initial Placement Forces  | :class:`tlp.StringCollection` | RandomRandIterNr |br| |br| Values for that parameter: |br| UniformGrid  |istart| (Uniform placement on a grid) |iend|  |br| RandomTime  |istart| (Random placement, based on current time) |iend|  |br| RandomRandIterNr  |istart| (Random placement, based on randIterNr()) |iend|  |br| KeepPositions  |istart| (No change in placement) |iend| | input       | Specifies how the initial placement is done.                                                                           |
+---------------------------+-------------------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------------------------------------------------------------+
| Reduced Tree Construction | :class:`tlp.StringCollection` | SubtreeBySubtree |br| |br| Values for that parameter: |br| PathByPath  |br|  SubtreeBySubtree                                                                                                                                                                                                                                                     | input       | Specifies how the reduced bucket quadtree is constructed.                                                              |
+---------------------------+-------------------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------------------------------------------------------------+
| Smallest Cell Finding     | :class:`tlp.StringCollection` | Iteratively |br| |br| Values for that parameter: |br| Iteratively  |istart| (Iteratively, in constant time) |iend|  |br| Aluru  |istart| (According to formula by Aluru et al., in constant time) |iend|                                                                                                                                          | input       | Specifies how to calculate the smallest quadratic cell surrounding particles of a node in the reduced bucket quadtree. |
+---------------------------+-------------------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('FM^3 (OGDF)', graph)

  # set any input parameter value if needed
  # params['Edge Length Property'] = ...
  # params['Node Size'] = ...
  # params['Unit edge length'] = ...
  # params['New initial placement'] = ...
  # params['Fixed iterations'] = ...
  # params['Threshold'] = ...
  # params['Page Format'] = ...
  # params['Quality vs Speed'] = ...
  # params['Edge Length Measurement'] = ...
  # params['Allowed Positions'] = ...
  # params['Tip Over'] = ...
  # params['Pre Sort'] = ...
  # params['Galaxy Choice'] = ...
  # params['Max Iter Change'] = ...
  # params['Initial Placement Mult'] = ...
  # params['Force Model'] = ...
  # params['Repulsive Force Method'] = ...
  # params['Initial Placement Forces'] = ...
  # params['Reduced Tree Construction'] = ...
  # params['Smallest Cell Finding'] = ...

  # either create or get a layout property from the graph to store the result of the algorithm
  resultLayout = graph.getLayoutProperty('resultLayout')
  success = graph.applyLayoutAlgorithm('FM^3 (OGDF)', resultLayout, params)

  # or store the result of the algorithm in the default Tulip layout property named 'viewLayout'
  success = graph.applyLayoutAlgorithm('FM^3 (OGDF)', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Fast Multipole Embedder (OGDF)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Implements the fast multipole embedder layout algorithm of Martin Gronemann.

Parameters
""""""""""

+------------------------+-----------------------+---------------+-------------+--------------------------------------------------------------------+
| name                   | type                  | default       | direction   | description                                                        |
+========================+=======================+===============+=============+====================================================================+
| number of iterations   | integer               | 100           | input       | The maximum number of iterations.                                  |
+------------------------+-----------------------+---------------+-------------+--------------------------------------------------------------------+
| number of coefficients | integer               | 5             | input       | The number of coefficients for the expansions.                     |
+------------------------+-----------------------+---------------+-------------+--------------------------------------------------------------------+
| randomize layout       | Boolean               | :const:`True` | input       | If true, the initial layout will be randomized.                    |
+------------------------+-----------------------+---------------+-------------+--------------------------------------------------------------------+
| default node size      | floating point number | 20.0          | input       | The default node size.                                             |
+------------------------+-----------------------+---------------+-------------+--------------------------------------------------------------------+
| default edge length    | floating point number | 1.0           | input       | The default edge length.                                           |
+------------------------+-----------------------+---------------+-------------+--------------------------------------------------------------------+
| number of threads      | integer               | 3             | input       | The number of threads to use during the computation of the layout. |
+------------------------+-----------------------+---------------+-------------+--------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Fast Multipole Embedder (OGDF)', graph)

  # set any input parameter value if needed
  # params['number of iterations'] = ...
  # params['number of coefficients'] = ...
  # params['randomize layout'] = ...
  # params['default node size'] = ...
  # params['default edge length'] = ...
  # params['number of threads'] = ...

  # either create or get a layout property from the graph to store the result of the algorithm
  resultLayout = graph.getLayoutProperty('resultLayout')
  success = graph.applyLayoutAlgorithm('Fast Multipole Embedder (OGDF)', resultLayout, params)

  # or store the result of the algorithm in the default Tulip layout property named 'viewLayout'
  success = graph.applyLayoutAlgorithm('Fast Multipole Embedder (OGDF)', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Fast Multipole Multilevel Embedder (OGDF)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

The FMME layout algorithm is a variant of multilevel, force-directed layout, which utilizes various tools to speed up the computation.

Parameters
""""""""""

+------------------------+---------+-----------+-------------+--------------------------------------------------------------------+
| name                   | type    |   default | direction   | description                                                        |
+========================+=========+===========+=============+====================================================================+
| number of threads      | integer |         2 | input       | The number of threads to use during the computation of the layout. |
+------------------------+---------+-----------+-------------+--------------------------------------------------------------------+
| multilevel nodes bound | integer |        10 | input       | The bound for the number of nodes in a multilevel step.            |
+------------------------+---------+-----------+-------------+--------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Fast Multipole Multilevel Embedder (OGDF)', graph)

  # set any input parameter value if needed
  # params['number of threads'] = ...
  # params['multilevel nodes bound'] = ...

  # either create or get a layout property from the graph to store the result of the algorithm
  resultLayout = graph.getLayoutProperty('resultLayout')
  success = graph.applyLayoutAlgorithm('Fast Multipole Multilevel Embedder (OGDF)', resultLayout, params)

  # or store the result of the algorithm in the default Tulip layout property named 'viewLayout'
  success = graph.applyLayoutAlgorithm('Fast Multipole Multilevel Embedder (OGDF)', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Fast Overlap Removal
^^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Implements a layout algorithm removing the nodes overlaps. It was first published as: |br|  |bstart| Fast Node Overlap Removal |bend| , Tim Dwyer, Kim Marriot, Peter J. Stuckey, Graph Drawing, Vol. 3843 (2006), pp. 153-164.

Parameters
""""""""""

+----------------------+-------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+---------------------------------------------------------------------------------------------------------------------------------------------------------+
| name                 | type                          | default                                                                                                                                                                                                                                       | direction   | description                                                                                                                                             |
+======================+===============================+===============================================================================================================================================================================================================================================+=============+=========================================================================================================================================================+
| overlap removal type | :class:`tlp.StringCollection` | X-Y |br| |br| Values for that parameter: |br| X-Y  |istart| (Remove overlaps in both X and Y directions) |iend|  |br| X  |istart| (Remove overlaps only in X direction) |iend|  |br| Y  |istart| (Remove overlaps only in Y direction) |iend| | input       | Overlap removal type.                                                                                                                                   |
+----------------------+-------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+---------------------------------------------------------------------------------------------------------------------------------------------------------+
| layout               | :class:`tlp.LayoutProperty`   | viewLayout                                                                                                                                                                                                                                    | input       | The property used for the input layout of nodes and edges.                                                                                              |
+----------------------+-------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+---------------------------------------------------------------------------------------------------------------------------------------------------------+
| bounding box         | :class:`tlp.SizeProperty`     | viewSize                                                                                                                                                                                                                                      | input       | The property used for node sizes.                                                                                                                       |
+----------------------+-------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+---------------------------------------------------------------------------------------------------------------------------------------------------------+
| rotation             | :class:`tlp.DoubleProperty`   | viewRotation                                                                                                                                                                                                                                  | input       | The property defining rotation angles of nodes around the z-axis.                                                                                       |
+----------------------+-------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+---------------------------------------------------------------------------------------------------------------------------------------------------------+
| number of passes     | integer                       | 5                                                                                                                                                                                                                                             | input       | The algorithm will be applied N times, each time increasing node size to attain original size at the final iteration. This greatly enhances the layout. |
+----------------------+-------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+---------------------------------------------------------------------------------------------------------------------------------------------------------+
| x border             | floating point number         | 0.0                                                                                                                                                                                                                                           | input       | The minimal x border value that will separate the graph nodes after application of the algorithm.                                                       |
+----------------------+-------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+---------------------------------------------------------------------------------------------------------------------------------------------------------+
| y border             | floating point number         | 0.0                                                                                                                                                                                                                                           | input       | The minimal y border value that will separate the graph nodes after application of the algorithm.                                                       |
+----------------------+-------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+---------------------------------------------------------------------------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Fast Overlap Removal', graph)

  # set any input parameter value if needed
  # params['overlap removal type'] = ...
  # params['layout'] = ...
  # params['bounding box'] = ...
  # params['rotation'] = ...
  # params['number of passes'] = ...
  # params['x border'] = ...
  # params['y border'] = ...

  # either create or get a layout property from the graph to store the result of the algorithm
  resultLayout = graph.getLayoutProperty('resultLayout')
  success = graph.applyLayoutAlgorithm('Fast Overlap Removal', resultLayout, params)

  # or store the result of the algorithm in the default Tulip layout property named 'viewLayout'
  success = graph.applyLayoutAlgorithm('Fast Overlap Removal', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Frutcherman Reingold (OGDF)
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Implements the Fruchterman and Reingold layout algorithm, first published as: |br|  |bstart| Graph Drawing by Force-Directed Placement |bend| , Fruchterman, Thomas M. J., Reingold, Edward M., Software – Practice & Experience (Wiley) Volume 21, Issue 11, pages 1129–1164, (1991)

Parameters
""""""""""

+-----------------------+-------------------------------+---------------------------------------------------------------------------+-------------+-------------------------------------------------------+
| name                  | type                          | default                                                                   | direction   | description                                           |
+=======================+===============================+===========================================================================+=============+=======================================================+
| iterations            | integer                       | 1000                                                                      | input       | The number of iterations.                             |
+-----------------------+-------------------------------+---------------------------------------------------------------------------+-------------+-------------------------------------------------------+
| noise                 | Boolean                       | :const:`True`                                                             | input       | Sets the parameter noise.                             |
+-----------------------+-------------------------------+---------------------------------------------------------------------------+-------------+-------------------------------------------------------+
| use node weights      | Boolean                       | :const:`False`                                                            | input       | Indicates if the node weights have to be used.        |
+-----------------------+-------------------------------+---------------------------------------------------------------------------+-------------+-------------------------------------------------------+
| node weights          | :class:`tlp.NumericProperty`  | viewMetric                                                                | input       | The metric containing node weights.                   |
+-----------------------+-------------------------------+---------------------------------------------------------------------------+-------------+-------------------------------------------------------+
| Cooling function      | :class:`tlp.StringCollection` | Factor |br| |br| Values for that parameter: |br| Factor |br|  Logarithmic | input       | Sets the parameter cooling function                   |
+-----------------------+-------------------------------+---------------------------------------------------------------------------+-------------+-------------------------------------------------------+
| ideal edge length     | floating point number         | 10.0                                                                      | input       | The ideal edge length.                                |
+-----------------------+-------------------------------+---------------------------------------------------------------------------+-------------+-------------------------------------------------------+
| minDistCC             | floating point number         | 20.0                                                                      | input       | The minimal distance between connected components.    |
+-----------------------+-------------------------------+---------------------------------------------------------------------------+-------------+-------------------------------------------------------+
| pageRatio             | floating point number         | 1.0                                                                       | input       | The page ratio used for packing connected components. |
+-----------------------+-------------------------------+---------------------------------------------------------------------------+-------------+-------------------------------------------------------+
| check convergence     | Boolean                       | :const:`True`                                                             | input       | Indicates if the convergence has to be checked.       |
+-----------------------+-------------------------------+---------------------------------------------------------------------------+-------------+-------------------------------------------------------+
| convergence tolerance | floating point number         | 0.01                                                                      | input       | The convergence tolerance parameter.                  |
+-----------------------+-------------------------------+---------------------------------------------------------------------------+-------------+-------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Frutcherman Reingold (OGDF)', graph)

  # set any input parameter value if needed
  # params['iterations'] = ...
  # params['noise'] = ...
  # params['use node weights'] = ...
  # params['node weights'] = ...
  # params['Cooling function'] = ...
  # params['ideal edge length'] = ...
  # params['minDistCC'] = ...
  # params['pageRatio'] = ...
  # params['check convergence'] = ...
  # params['convergence tolerance'] = ...

  # either create or get a layout property from the graph to store the result of the algorithm
  resultLayout = graph.getLayoutProperty('resultLayout')
  success = graph.applyLayoutAlgorithm('Frutcherman Reingold (OGDF)', resultLayout, params)

  # or store the result of the algorithm in the default Tulip layout property named 'viewLayout'
  success = graph.applyLayoutAlgorithm('Frutcherman Reingold (OGDF)', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

GEM (Frick)
^^^^^^^^^^^

Description
"""""""""""

Implements the GEM-2d layout algorithm first published as: |br|   |bstart| A fast, adaptive layout algorithm for undirected graphs |bend| , A. Frick, A. Ludwig, and H. Mehldau, Graph Drawing'94, Volume 894 of Lecture Notes in Computer Science (1995).

Parameters
""""""""""

+-----------------+------------------------------+----------------+-------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| name            | type                         | default        | direction   | description                                                                                                                                                                                                                                                      |
+=================+==============================+================+=============+==================================================================================================================================================================================================================================================================+
| 3D layout       | Boolean                      | :const:`False` | input       | If true, the layout is in 3D else it is computed in 2D.                                                                                                                                                                                                          |
+-----------------+------------------------------+----------------+-------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| edge length     | :class:`tlp.NumericProperty` |                | input       | This metric is used to compute the length of edges.                                                                                                                                                                                                              |
+-----------------+------------------------------+----------------+-------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| initial layout  | :class:`tlp.LayoutProperty`  |                | input       | The layout property used to compute the initial position of the graph elements. If none is given the initial position will be computed by the algorithm.                                                                                                         |
+-----------------+------------------------------+----------------+-------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| unmovable nodes | :class:`tlp.BooleanProperty` |                | input       | This property is used to indicate the unmovable nodes, the ones for which a new position will not be computed by the algorithm. This property is taken into account only if a layout property has been given to get the initial position of the unmovable nodes. |
+-----------------+------------------------------+----------------+-------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| max iterations  | unsigned integer             | 0              | input       | This parameter allows to choose the number of iterations. The default value of 0 corresponds to (3 * nb_nodes * nb_nodes) if the graph has more than 100 nodes. For smaller graph, the number of iterations is set to 30 000.                                    |
+-----------------+------------------------------+----------------+-------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('GEM (Frick)', graph)

  # set any input parameter value if needed
  # params['3D layout'] = ...
  # params['edge length'] = ...
  # params['initial layout'] = ...
  # params['unmovable nodes'] = ...
  # params['max iterations'] = ...

  # either create or get a layout property from the graph to store the result of the algorithm
  resultLayout = graph.getLayoutProperty('resultLayout')
  success = graph.applyLayoutAlgorithm('GEM (Frick)', resultLayout, params)

  # or store the result of the algorithm in the default Tulip layout property named 'viewLayout'
  success = graph.applyLayoutAlgorithm('GEM (Frick)', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

GEM Frick (OGDF)
^^^^^^^^^^^^^^^^

Description
"""""""""""

Implements the GEM-2d layout algorithm first published as: |br|   |bstart| A fast, adaptive layout algorithm for undirected graphs |bend| , A. Frick, A. Ludwig, and H. Mehldau, Graph Drawing'94, Volume 894 of Lecture Notes in Computer Science (1995).

Parameters
""""""""""

+-------------------------+-------------------------------+------------------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------+
| name                    | type                          | default                                                                                        | direction   | description                                                      |
+=========================+===============================+================================================================================================+=============+==================================================================+
| number of rounds        | integer                       | 30000                                                                                          | input       | The maximal number of rounds per node.                           |
+-------------------------+-------------------------------+------------------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------+
| minimal temperature     | floating point number         | 0.005                                                                                          | input       | The minimal temperature.                                         |
+-------------------------+-------------------------------+------------------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------+
| initial temperature     | floating point number         | 12.0                                                                                           | input       | The initial temperature to x; must be >= minimalTemperature.     |
+-------------------------+-------------------------------+------------------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------+
| gravitational constant  | floating point number         | 0.0625                                                                                         | input       | Gravitational constant parameter.                                |
+-------------------------+-------------------------------+------------------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------+
| desired length          | floating point number         | 5.0                                                                                            | input       | The desired edge length to x; must be >= 0.                      |
+-------------------------+-------------------------------+------------------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------+
| maximal disturbance     | floating point number         | 0.0                                                                                            | input       | The maximal disturbance to x; must be >= 0.                      |
+-------------------------+-------------------------------+------------------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------+
| rotation angle          | floating point number         | 1.04719755                                                                                     | input       | The opening angle for rotations to x (0 <= x <= pi / 2).         |
+-------------------------+-------------------------------+------------------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------+
| oscillation angle       | floating point number         | 1.57079633                                                                                     | input       | Sets the opening angle for oscillations to x (0 <= x <= pi / 2). |
+-------------------------+-------------------------------+------------------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------+
| rotation sensitivity    | floating point number         | 0.01                                                                                           | input       | The rotation sensitivity to x (0 <= x <= 1).                     |
+-------------------------+-------------------------------+------------------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------+
| oscillation sensitivity | floating point number         | 0.3                                                                                            | input       | The oscillation sensitivity to x (0 <= x <= 1).                  |
+-------------------------+-------------------------------+------------------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------+
| Attraction formula      | :class:`tlp.StringCollection` | Fruchterman/Reingold |br| |br| Values for that parameter: |br| Fruchterman/Reingold  |br|  GEM | input       | The formula for attraction.                                      |
+-------------------------+-------------------------------+------------------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------+
| minDistCC               | floating point number         | 20                                                                                             | input       | The minimal distance between connected components.               |
+-------------------------+-------------------------------+------------------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------+
| pageRatio               | floating point number         | 1.0                                                                                            | input       | The page ratio used for packing connected components.            |
+-------------------------+-------------------------------+------------------------------------------------------------------------------------------------+-------------+------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('GEM Frick (OGDF)', graph)

  # set any input parameter value if needed
  # params['number of rounds'] = ...
  # params['minimal temperature'] = ...
  # params['initial temperature'] = ...
  # params['gravitational constant'] = ...
  # params['desired length'] = ...
  # params['maximal disturbance'] = ...
  # params['rotation angle'] = ...
  # params['oscillation angle'] = ...
  # params['rotation sensitivity'] = ...
  # params['oscillation sensitivity'] = ...
  # params['Attraction formula'] = ...
  # params['minDistCC'] = ...
  # params['pageRatio'] = ...

  # either create or get a layout property from the graph to store the result of the algorithm
  resultLayout = graph.getLayoutProperty('resultLayout')
  success = graph.applyLayoutAlgorithm('GEM Frick (OGDF)', resultLayout, params)

  # or store the result of the algorithm in the default Tulip layout property named 'viewLayout'
  success = graph.applyLayoutAlgorithm('GEM Frick (OGDF)', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

GRIP
^^^^

Description
"""""""""""

Implements a force directed graph drawing algorithm first published as: |br|  |bstart| GRIP: Graph dRawing with Intelligent Placement |bend| , P. Gajer and S.G. Kobourov, Journal Graph Algorithm and Applications, vol. 6, no. 3, pages 203--224, (2002).

Parameters
""""""""""

+-----------+---------+----------------+-------------+-------------------------------------------------------+
| name      | type    | default        | direction   | description                                           |
+===========+=========+================+=============+=======================================================+
| 3D layout | Boolean | :const:`False` | input       | If true the layout is in 3D else it is computed in 2D |
+-----------+---------+----------------+-------------+-------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('GRIP', graph)

  # set any input parameter value if needed
  # params['3D layout'] = ...

  # either create or get a layout property from the graph to store the result of the algorithm
  resultLayout = graph.getLayoutProperty('resultLayout')
  success = graph.applyLayoutAlgorithm('GRIP', resultLayout, params)

  # or store the result of the algorithm in the default Tulip layout property named 'viewLayout'
  success = graph.applyLayoutAlgorithm('GRIP', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Hierarchical Graph
^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Implements the hierarchical layout algorithm  first published as: |br|  |bstart| Tulip - A Huge Graph Visualization Framework |bend| , D. Auber, Book. Graph Drawing Software. (Ed. Michael Junger & Petra Mutzel) pages 105--126. (2004).

Parameters
""""""""""

+---------------+-------------------------------+---------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------------------------+
| name          | type                          | default                                                                         | direction   | description                                                                             |
+===============+===============================+=================================================================================+=============+=========================================================================================+
| node size     | :class:`tlp.SizeProperty`     | viewSize                                                                        | input       | This parameter defines the property used for node sizes.                                |
+---------------+-------------------------------+---------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------------------------+
| orientation   | :class:`tlp.StringCollection` | horizontal |br| |br| Values for that parameter: |br| horizontal  |br|  vertical | input       | This parameter enables to choose the orientation of the drawing.                        |
+---------------+-------------------------------+---------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------------------------+
| layer spacing | floating point number         | 64.                                                                             | input       | This parameter enables to set up the minimum space between two layers in the drawing.   |
+---------------+-------------------------------+---------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------------------------+
| node spacing  | floating point number         | 18.                                                                             | input       | This parameter enables to set up the minimum space between two nodes in the same layer. |
+---------------+-------------------------------+---------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Hierarchical Graph', graph)

  # set any input parameter value if needed
  # params['node size'] = ...
  # params['orientation'] = ...
  # params['layer spacing'] = ...
  # params['node spacing'] = ...

  # either create or get a layout property from the graph to store the result of the algorithm
  resultLayout = graph.getLayoutProperty('resultLayout')
  success = graph.applyLayoutAlgorithm('Hierarchical Graph', resultLayout, params)

  # or store the result of the algorithm in the default Tulip layout property named 'viewLayout'
  success = graph.applyLayoutAlgorithm('Hierarchical Graph', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Hierarchical Tree (R-T Extended)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Implements the hierarchical tree layout algorithm first published as: |br|  |bstart| Tidier Drawings of Trees |bend| , E.M. Reingold and J.S. Tilford, IEEE Transactions on Software Engineering pages 223--228 (1981).

Parameters
""""""""""

+------------------+-------------------------------+-------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------------------------+
| name             | type                          | default                                                                       | direction   | description                                                                             |
+==================+===============================+===============================================================================+=============+=========================================================================================+
| node size        | :class:`tlp.SizeProperty`     | viewSize                                                                      | input       | This parameter defines the property used for node sizes.                                |
+------------------+-------------------------------+-------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------------------------+
| edge length      | :class:`tlp.IntegerProperty`  |                                                                               | input       | This parameter indicates the property used to compute the length of edges.              |
+------------------+-------------------------------+-------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------------------------+
| orientation      | :class:`tlp.StringCollection` | vertical |br| |br| Values for that parameter: |br| vertical  |br|  horizontal | input       | This parameter enables to choose the orientation of the drawing.                        |
+------------------+-------------------------------+-------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------------------------+
| orthogonal       | Boolean                       | :const:`True`                                                                 | input       | This parameter enables to choose if the tree is drawn orthogonally or not.              |
+------------------+-------------------------------+-------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------------------------+
| layer spacing    | floating point number         | 64.                                                                           | input       | This parameter enables to set up the minimum space between two layers in the drawing.   |
+------------------+-------------------------------+-------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------------------------+
| node spacing     | floating point number         | 18.                                                                           | input       | This parameter enables to set up the minimum space between two nodes in the same layer. |
+------------------+-------------------------------+-------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------------------------+
| bounding circles | Boolean                       | :const:`False`                                                                | input       | Indicates if the node bounding objects are boxes or bounding circles.                   |
+------------------+-------------------------------+-------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------------------------+
| compact layout   | Boolean                       | :const:`True`                                                                 | input       | Indicates if a compact layout is computed.                                              |
+------------------+-------------------------------+-------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Hierarchical Tree (R-T Extended)', graph)

  # set any input parameter value if needed
  # params['node size'] = ...
  # params['edge length'] = ...
  # params['orientation'] = ...
  # params['orthogonal'] = ...
  # params['layer spacing'] = ...
  # params['node spacing'] = ...
  # params['bounding circles'] = ...
  # params['compact layout'] = ...

  # either create or get a layout property from the graph to store the result of the algorithm
  resultLayout = graph.getLayoutProperty('resultLayout')
  success = graph.applyLayoutAlgorithm('Hierarchical Tree (R-T Extended)', resultLayout, params)

  # or store the result of the algorithm in the default Tulip layout property named 'viewLayout'
  success = graph.applyLayoutAlgorithm('Hierarchical Tree (R-T Extended)', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Improved Walker
^^^^^^^^^^^^^^^

Description
"""""""""""

It is a linear implementation of the Walker's tree layout improved algorithm described in |br|  |bstart| Improving Walker's Algorithm to Run in Linear Time |bend| , Christoph Buchheim and Michael Junger and Sebastian Leipert (2002).

Parameters
""""""""""

+---------------+-------------------------------+-----------------------------------------------------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------------------------+
| name          | type                          | default                                                                                                                     | direction   | description                                                                             |
+===============+===============================+=============================================================================================================================+=============+=========================================================================================+
| node size     | :class:`tlp.SizeProperty`     | viewSize                                                                                                                    | input       | This parameter defines the property used for node sizes.                                |
+---------------+-------------------------------+-----------------------------------------------------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------------------------+
| orientation   | :class:`tlp.StringCollection` | up to down |br| |br| Values for that parameter: |br| up to down  |br|  down to up  |br|  right to left  |br|  left to right | input       | Choose a desired orientation.                                                           |
+---------------+-------------------------------+-----------------------------------------------------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------------------------+
| orthogonal    | Boolean                       | :const:`False`                                                                                                              | input       | If true then use orthogonal edges.                                                      |
+---------------+-------------------------------+-----------------------------------------------------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------------------------+
| layer spacing | floating point number         | 64.                                                                                                                         | input       | This parameter enables to set up the minimum space between two layers in the drawing.   |
+---------------+-------------------------------+-----------------------------------------------------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------------------------+
| node spacing  | floating point number         | 18.                                                                                                                         | input       | This parameter enables to set up the minimum space between two nodes in the same layer. |
+---------------+-------------------------------+-----------------------------------------------------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Improved Walker', graph)

  # set any input parameter value if needed
  # params['node size'] = ...
  # params['orientation'] = ...
  # params['orthogonal'] = ...
  # params['layer spacing'] = ...
  # params['node spacing'] = ...

  # either create or get a layout property from the graph to store the result of the algorithm
  resultLayout = graph.getLayoutProperty('resultLayout')
  success = graph.applyLayoutAlgorithm('Improved Walker', resultLayout, params)

  # or store the result of the algorithm in the default Tulip layout property named 'viewLayout'
  success = graph.applyLayoutAlgorithm('Improved Walker', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Improved Walker (OGDF)
^^^^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Implements a linear-time tree layout algorithm with straight-line or orthogonal edge routing.

Parameters
""""""""""

+-------------------+-------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------+
| name              | type                          | default                                                                                                                                                                                                                                                                                                                                                     | direction   | description                                                           |
+===================+===============================+=============================================================================================================================================================================================================================================================================================================================================================+=============+=======================================================================+
| siblings distance | floating point number         | 20                                                                                                                                                                                                                                                                                                                                                          | input       | The minimal required horizontal distance between siblings.            |
+-------------------+-------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------+
| subtrees distance | floating point number         | 20                                                                                                                                                                                                                                                                                                                                                          | input       | The minimal required horizontal distance between subtrees.            |
+-------------------+-------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------+
| levels distance   | floating point number         | 50                                                                                                                                                                                                                                                                                                                                                          | input       | The minimal required vertical distance between levels.                |
+-------------------+-------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------+
| trees distance    | floating point number         | 50                                                                                                                                                                                                                                                                                                                                                          | input       | The minimal required horizontal distance between trees in the forest. |
+-------------------+-------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------+
| orthogonal layout | Boolean                       | :const:`False`                                                                                                                                                                                                                                                                                                                                              | input       | Indicates whether orthogonal edge routing style is used or not.       |
+-------------------+-------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------+
| Orientation       | :class:`tlp.StringCollection` | topToBottom |br| |br| Values for that parameter: |br| topToBottom  |istart| (Edges are oriented from top to bottom) |iend|  |br| bottomToTop  |istart| (Edges are oriented from bottom to top) |iend|  |br| leftToRight  |istart| (Edges are oriented from left to right) |iend|  |br| rightToLeft  |istart| (Edges are oriented from right to left) |iend| | input       | This parameter indicates the orientation of the layout.               |
+-------------------+-------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------+
| Root selection    | :class:`tlp.StringCollection` | rootIsSource |br| |br| Values for that parameter: |br| rootIsSource  |istart| (Select a source in the graph) |iend|  |br| rootIsSink  |istart| (Select a sink in the graph) |iend|  |br| rootByCoord  |istart| (Use the coordinates, e.g., select the topmost node if orientation is topToBottom) |iend|                                                    | input       | This parameter indicates how the root is selected.                    |
+-------------------+-------------------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Improved Walker (OGDF)', graph)

  # set any input parameter value if needed
  # params['siblings distance'] = ...
  # params['subtrees distance'] = ...
  # params['levels distance'] = ...
  # params['trees distance'] = ...
  # params['orthogonal layout'] = ...
  # params['Orientation'] = ...
  # params['Root selection'] = ...

  # either create or get a layout property from the graph to store the result of the algorithm
  resultLayout = graph.getLayoutProperty('resultLayout')
  success = graph.applyLayoutAlgorithm('Improved Walker (OGDF)', resultLayout, params)

  # or store the result of the algorithm in the default Tulip layout property named 'viewLayout'
  success = graph.applyLayoutAlgorithm('Improved Walker (OGDF)', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Kamada Kawai (OGDF)
^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Implements the Kamada-Kawai layout algorithm. |br| It is a force-directed layout algorithm that tries to place vertices with a distance corresponding to their graph theoretic distance. 

Parameters
""""""""""

+------------------------+-----------------------+---------------+-------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| name                   | type                  | default       | direction   | description                                                                                                                                                                            |
+========================+=======================+===============+=============+========================================================================================================================================================================================+
| stop tolerance         | floating point number | 0.001         | input       | The value for the stop tolerance, below which the system is regarded stable (balanced) and the optimization stopped.                                                                   |
+------------------------+-----------------------+---------------+-------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| used layout            | Boolean               | :const:`True` | input       | If set to true, the given layout is used for the initial positions.                                                                                                                    |
+------------------------+-----------------------+---------------+-------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| zero length            | floating point number | 0             | input       | If set != 0, value zerolength is used to determine the desirable edge length by L = zerolength / max distance_ij. Otherwise, zerolength is determined using the node number and sizes. |
+------------------------+-----------------------+---------------+-------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| edge length            | floating point number | 0             | input       | The desirable edge length.                                                                                                                                                             |
+------------------------+-----------------------+---------------+-------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| compute max iterations | Boolean               | :const:`True` | input       | If set to true, the number of iterations is computed depending on G.                                                                                                                   |
+------------------------+-----------------------+---------------+-------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| global iterations      | integer               | 50            | input       | The number of global iterations.                                                                                                                                                       |
+------------------------+-----------------------+---------------+-------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| local iterations       | integer               | 50            | input       | The number of local iterations.                                                                                                                                                        |
+------------------------+-----------------------+---------------+-------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Kamada Kawai (OGDF)', graph)

  # set any input parameter value if needed
  # params['stop tolerance'] = ...
  # params['used layout'] = ...
  # params['zero length'] = ...
  # params['edge length'] = ...
  # params['compute max iterations'] = ...
  # params['global iterations'] = ...
  # params['local iterations'] = ...

  # either create or get a layout property from the graph to store the result of the algorithm
  resultLayout = graph.getLayoutProperty('resultLayout')
  success = graph.applyLayoutAlgorithm('Kamada Kawai (OGDF)', resultLayout, params)

  # or store the result of the algorithm in the default Tulip layout property named 'viewLayout'
  success = graph.applyLayoutAlgorithm('Kamada Kawai (OGDF)', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

LinLog
^^^^^^

Description
"""""""""""

Implements the LinLog layout algorithm, an energy model layout algorithm, first published as: |br|  |bstart| Energy Models for Graph Clustering |bend| , Andreas Noack., Journal of Graph Algorithms and Applications 11(2):453-480, 2007.

Parameters
""""""""""

+---------------------+------------------------------+----------------+-------------+----------------------------------------------------------------------------------------------------------------------------------------------------------+
| name                | type                         | default        | direction   | description                                                                                                                                              |
+=====================+==============================+================+=============+==========================================================================================================================================================+
| 3D layout           | Boolean                      | :const:`False` | input       | If true the layout is in 3D else it is computed in 2D                                                                                                    |
+---------------------+------------------------------+----------------+-------------+----------------------------------------------------------------------------------------------------------------------------------------------------------+
| octtree             | Boolean                      | :const:`True`  | input       | If true, use the OctTree optimization                                                                                                                    |
+---------------------+------------------------------+----------------+-------------+----------------------------------------------------------------------------------------------------------------------------------------------------------+
| edge weight         | :class:`tlp.NumericProperty` |                | input       | This property is used to compute the length of edges.                                                                                                    |
+---------------------+------------------------------+----------------+-------------+----------------------------------------------------------------------------------------------------------------------------------------------------------+
| max iterations      | unsigned integer             | 100            | input       | This parameter allows to limit the number of iterations. The value of 0 corresponds to a default value of 100.                                           |
+---------------------+------------------------------+----------------+-------------+----------------------------------------------------------------------------------------------------------------------------------------------------------+
| repulsion exponent  | floating point number        | 0.0            | input       | This parameter allows to set the exponent of attraction.                                                                                                 |
+---------------------+------------------------------+----------------+-------------+----------------------------------------------------------------------------------------------------------------------------------------------------------+
| attraction exponent | floating point number        | 1.0            | input       | This parameter allows to set the exponent of repulsion.                                                                                                  |
+---------------------+------------------------------+----------------+-------------+----------------------------------------------------------------------------------------------------------------------------------------------------------+
| gravitation factor  | floating point number        | 0.05           | input       | This parameter allows to set the factor of gravitation.                                                                                                  |
+---------------------+------------------------------+----------------+-------------+----------------------------------------------------------------------------------------------------------------------------------------------------------+
| skip nodes          | :class:`tlp.BooleanProperty` |                | input       | This boolean property is used to skip nodes in computation when their value are set to true.                                                             |
+---------------------+------------------------------+----------------+-------------+----------------------------------------------------------------------------------------------------------------------------------------------------------+
| initial layout      | :class:`tlp.LayoutProperty`  |                | input       | The layout property used to compute the initial position of the graph elements. If none is given the initial position will be computed by the algorithm. |
+---------------------+------------------------------+----------------+-------------+----------------------------------------------------------------------------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('LinLog', graph)

  # set any input parameter value if needed
  # params['3D layout'] = ...
  # params['octtree'] = ...
  # params['edge weight'] = ...
  # params['max iterations'] = ...
  # params['repulsion exponent'] = ...
  # params['attraction exponent'] = ...
  # params['gravitation factor'] = ...
  # params['skip nodes'] = ...
  # params['initial layout'] = ...

  # either create or get a layout property from the graph to store the result of the algorithm
  resultLayout = graph.getLayoutProperty('resultLayout')
  success = graph.applyLayoutAlgorithm('LinLog', resultLayout, params)

  # or store the result of the algorithm in the default Tulip layout property named 'viewLayout'
  success = graph.applyLayoutAlgorithm('LinLog', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

MMM Example Fast Layout (OGDF)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Implements a fast multilevel graph layout using the OGDF modular multilevel-mixer. SolarMerger and SolarPlacer are used as merging and placement strategies.

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('MMM Example Fast Layout (OGDF)', graph)

  # either create or get a layout property from the graph to store the result of the algorithm
  resultLayout = graph.getLayoutProperty('resultLayout')
  success = graph.applyLayoutAlgorithm('MMM Example Fast Layout (OGDF)', resultLayout, params)

  # or store the result of the algorithm in the default Tulip layout property named 'viewLayout'
  success = graph.applyLayoutAlgorithm('MMM Example Fast Layout (OGDF)', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

MMM Example Nice Layout (OGDF)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Implements a nice multilevel graph layout using the OGDF modular multilevel-mixer. EdgeCoverMerger and BarycenterPlacer are used as merging and placement strategies.

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('MMM Example Nice Layout (OGDF)', graph)

  # either create or get a layout property from the graph to store the result of the algorithm
  resultLayout = graph.getLayoutProperty('resultLayout')
  success = graph.applyLayoutAlgorithm('MMM Example Nice Layout (OGDF)', resultLayout, params)

  # or store the result of the algorithm in the default Tulip layout property named 'viewLayout'
  success = graph.applyLayoutAlgorithm('MMM Example Nice Layout (OGDF)', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

MMM Example No Twist Layout (OGDF)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Implements a multilevel graph layout with using the OGDF modular multilevel-mixer. It is tuned to reduce twists in the final drawing and uses LocalBiconnectedMerger and BarycenterPlacer as merging and placement strategies.

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('MMM Example No Twist Layout (OGDF)', graph)

  # either create or get a layout property from the graph to store the result of the algorithm
  resultLayout = graph.getLayoutProperty('resultLayout')
  success = graph.applyLayoutAlgorithm('MMM Example No Twist Layout (OGDF)', resultLayout, params)

  # or store the result of the algorithm in the default Tulip layout property named 'viewLayout'
  success = graph.applyLayoutAlgorithm('MMM Example No Twist Layout (OGDF)', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Mixed Model
^^^^^^^^^^^

Description
"""""""""""

Implements the planar polyline graph drawing algorithm, the mixed model algorithm, first published as: |br|  |bstart| Planar Polyline Drawings with Good Angular Resolution |bend| , C. Gutwenger and P. Mutzel, LNCS, Vol. 1547 pages 167--182 (1998).

Parameters
""""""""""

+-----------------------------------+-------------------------------+-------------------------------------------------------------------------------+----------------+---------------------------------------------------------------------------------------------------+
| name                              | type                          | default                                                                       | direction      | description                                                                                       |
+===================================+===============================+===============================================================================+================+===================================================================================================+
| node size                         | :class:`tlp.SizeProperty`     | viewSize                                                                      | input / output | This parameter defines the property used for node sizes.                                          |
+-----------------------------------+-------------------------------+-------------------------------------------------------------------------------+----------------+---------------------------------------------------------------------------------------------------+
| orientation                       | :class:`tlp.StringCollection` | vertical |br| |br| Values for that parameter: |br| vertical  |br|  horizontal | input          | This parameter enables to choose the orientation of the drawing.                                  |
+-----------------------------------+-------------------------------+-------------------------------------------------------------------------------+----------------+---------------------------------------------------------------------------------------------------+
| y node-node spacing               | floating point number         | 2                                                                             | input          | This parameter defines the minimum y-spacing between any two nodes.                               |
+-----------------------------------+-------------------------------+-------------------------------------------------------------------------------+----------------+---------------------------------------------------------------------------------------------------+
| x node-node and edge-node spacing | floating point number         | 2                                                                             | input          | This parameter defines the minimum x-spacing between any two nodes or between a node and an edge. |
+-----------------------------------+-------------------------------+-------------------------------------------------------------------------------+----------------+---------------------------------------------------------------------------------------------------+
| node shape                        | :class:`tlp.IntegerProperty`  | viewShape                                                                     | output         | This parameter defines the property holding node shapes.                                          |
+-----------------------------------+-------------------------------+-------------------------------------------------------------------------------+----------------+---------------------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Mixed Model', graph)

  # set any input parameter value if needed
  # params['node size'] = ...
  # params['orientation'] = ...
  # params['y node-node spacing'] = ...
  # params['x node-node and edge-node spacing'] = ...
  # params['node shape'] = ...

  # either create or get a layout property from the graph to store the result of the algorithm
  resultLayout = graph.getLayoutProperty('resultLayout')
  success = graph.applyLayoutAlgorithm('Mixed Model', resultLayout, params)

  # or store the result of the algorithm in the default Tulip layout property named 'viewLayout'
  success = graph.applyLayoutAlgorithm('Mixed Model', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Perfect aspect ratio
^^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Scales the graph layout to get an aspect ratio of 1.

Parameters
""""""""""

+---------------+-----------------------------+----------------+-------------+---------------------------------------------------------------------------+
| name          | type                        | default        | direction   | description                                                               |
+===============+=============================+================+=============+===========================================================================+
| layout        | :class:`tlp.LayoutProperty` | viewLayout     | input       | The layout property from which a perfect aspect ratio has to be computed. |
+---------------+-----------------------------+----------------+-------------+---------------------------------------------------------------------------+
| Subgraph only | Boolean                     | :const:`False` | input       | When applied on a subgraph, scales only the layout of this subgraph       |
+---------------+-----------------------------+----------------+-------------+---------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Perfect aspect ratio', graph)

  # set any input parameter value if needed
  # params['layout'] = ...
  # params['Subgraph only'] = ...

  # either create or get a layout property from the graph to store the result of the algorithm
  resultLayout = graph.getLayoutProperty('resultLayout')
  success = graph.applyLayoutAlgorithm('Perfect aspect ratio', resultLayout, params)

  # or store the result of the algorithm in the default Tulip layout property named 'viewLayout'
  success = graph.applyLayoutAlgorithm('Perfect aspect ratio', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Pivot MDS (OGDF)
^^^^^^^^^^^^^^^^

Description
"""""""""""

By setting the number of pivots to infinity this algorithm behaves just like classical MDS. See Brandes and Pich: Eigensolver methods for progressive multidimensional scaling of large data.

Parameters
""""""""""

+------------------+-----------------------+----------------+-------------+---------------------------------------------------------------------------------------------------------------------------+
| name             | type                  | default        | direction   | description                                                                                                               |
+==================+=======================+================+=============+===========================================================================================================================+
| number of pivots | integer               | 250            | input       | Sets the number of pivots. If the new value is smaller or equal 0 the default value (250) is used.                        |
+------------------+-----------------------+----------------+-------------+---------------------------------------------------------------------------------------------------------------------------+
| use edge costs   | Boolean               | :const:`False` | input       | Sets if the edge costs attribute has to be used.                                                                          |
+------------------+-----------------------+----------------+-------------+---------------------------------------------------------------------------------------------------------------------------+
| edge costs       | floating point number | 100            | input       | Sets the desired distance between adjacent nodes. If the new value is smaller or equal 0 the default value (100) is used. |
+------------------+-----------------------+----------------+-------------+---------------------------------------------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Pivot MDS (OGDF)', graph)

  # set any input parameter value if needed
  # params['number of pivots'] = ...
  # params['use edge costs'] = ...
  # params['edge costs'] = ...

  # either create or get a layout property from the graph to store the result of the algorithm
  resultLayout = graph.getLayoutProperty('resultLayout')
  success = graph.applyLayoutAlgorithm('Pivot MDS (OGDF)', resultLayout, params)

  # or store the result of the algorithm in the default Tulip layout property named 'viewLayout'
  success = graph.applyLayoutAlgorithm('Pivot MDS (OGDF)', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Planarization Grid (OGDF)
^^^^^^^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

The planarization grid layout algorithm applies the planarization approach for crossing minimization, combined with the topology-shape-metrics approach for orthogonal planar graph drawing. It produces drawings with few crossings and is suited for small to medium sized sparse graphs. It uses a planar grid layout algorithm to produce a drawing on a grid.

Parameters
""""""""""

+------------+-----------------------+-----------+-------------+----------------------------+
| name       | type                  |   default | direction   | description                |
+============+=======================+===========+=============+============================+
| page ratio | floating point number |       1.1 | input       | Sets the option pageRatio. |
+------------+-----------------------+-----------+-------------+----------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Planarization Grid (OGDF)', graph)

  # set any input parameter value if needed
  # params['page ratio'] = ...

  # either create or get a layout property from the graph to store the result of the algorithm
  resultLayout = graph.getLayoutProperty('resultLayout')
  success = graph.applyLayoutAlgorithm('Planarization Grid (OGDF)', resultLayout, params)

  # or store the result of the algorithm in the default Tulip layout property named 'viewLayout'
  success = graph.applyLayoutAlgorithm('Planarization Grid (OGDF)', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Planarization Layout (OGDF)
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

The planarization approach for drawing graphs.

Parameters
""""""""""

+------------+-------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| name       | type                          | default                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         | direction   | description                                                                                                                                                                         |
+============+===============================+=================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================+=============+=====================================================================================================================================================================================+
| page ratio | floating point number         | 1.1                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             | input       | Sets the option page ratio.                                                                                                                                                         |
+------------+-------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| Embedder   | :class:`tlp.StringCollection` | SimpleEmbedder |br| |br| Values for that parameter: |br| SimpleEmbedder  |istart| (Planar graph embedding from the algorithm of Boyer and Myrvold) |iend|  |br| EmbedderMaxFace  |istart| (Planar graph embedding with maximum external face) |iend|  |br| EmbedderMaxFaceLayers  |istart| (Planar graph embedding with maximum external face, plus layers approach) |iend|  |br| EmbedderMinDepth  |istart| (Planar graph embedding with minimum block-nesting depth) |iend|  |br| EmbedderMinDepthMaxFace  |istart| (Planar graph embedding with minimum block-nesting depth and maximum external face) |iend|  |br| EmbedderMinDepthMaxFaceLayers  |istart| (Planar graph embedding with minimum block-nesting depth and maximum external face, plus layers approach) |iend|  |br| EmbedderMinDepthPiTa  |istart| (Planar graph embedding with minimum block-nesting depth for given embedded blocks) |iend| | input       | The result of the crossing minimization step is a planar graph, in which crossings are replaced by dummy nodes. The embedder then computes a planar embedding of this planar graph. |
+------------+-------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Planarization Layout (OGDF)', graph)

  # set any input parameter value if needed
  # params['page ratio'] = ...
  # params['Embedder'] = ...

  # either create or get a layout property from the graph to store the result of the algorithm
  resultLayout = graph.getLayoutProperty('resultLayout')
  success = graph.applyLayoutAlgorithm('Planarization Layout (OGDF)', resultLayout, params)

  # or store the result of the algorithm in the default Tulip layout property named 'viewLayout'
  success = graph.applyLayoutAlgorithm('Planarization Layout (OGDF)', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Random layout
^^^^^^^^^^^^^

Description
"""""""""""

The positions of the graph nodes are randomly selected.

Parameters
""""""""""

+-----------+---------+----------------+-------------+-------------------------------------------------------------------+
| name      | type    | default        | direction   | description                                                       |
+===========+=========+================+=============+===================================================================+
| 3D layout | Boolean | :const:`False` | input       | If true, the layout is computed in 3D, else it is computed in 2D. |
+-----------+---------+----------------+-------------+-------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Random layout', graph)

  # set any input parameter value if needed
  # params['3D layout'] = ...

  # either create or get a layout property from the graph to store the result of the algorithm
  resultLayout = graph.getLayoutProperty('resultLayout')
  success = graph.applyLayoutAlgorithm('Random layout', resultLayout, params)

  # or store the result of the algorithm in the default Tulip layout property named 'viewLayout'
  success = graph.applyLayoutAlgorithm('Random layout', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Squarified Tree Map
^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Implements a TreeMap and Squarified Treemap layout. |br| For Treemap see: |br|  |bstart| Tree visualization with treemaps: a 2-d space-filling approach |bend|  , Shneiderman B., ACM Transactions on Graphics, vol. 11, 1 pages 92-99 (1992). |br|  For Squarified Treemaps see: |br|  Bruls, M., Huizing, K., & van Wijk, J. J. Proc. of Joint Eurographics and IEEE TCVG Symp. on Visualization (TCVG 2000) IEEE Press, pp. 33-42.

Parameters
""""""""""

+--------------+------------------------------+----------------+-------------+--------------------------------------------------------------------------------------------------------------------+
| name         | type                         | default        | direction   | description                                                                                                        |
+==============+==============================+================+=============+====================================================================================================================+
| metric       | :class:`tlp.NumericProperty` | viewMetric     | input       | This parameter defines the metric used to estimate the size allocated to each node.                                |
+--------------+------------------------------+----------------+-------------+--------------------------------------------------------------------------------------------------------------------+
| Aspect Ratio | floating point number        | 1.             | input       | This parameter enables to set up the aspect ratio (height/width) for the rectangle corresponding to the root node. |
+--------------+------------------------------+----------------+-------------+--------------------------------------------------------------------------------------------------------------------+
| Treemap Type | Boolean                      | :const:`False` | input       | This parameter indicates to use normal Treemaps (B. Shneiderman) or Squarified Treemaps (J. J. van Wijk)           |
+--------------+------------------------------+----------------+-------------+--------------------------------------------------------------------------------------------------------------------+
| Node Size    | :class:`tlp.SizeProperty`    | viewSize       | output      | This parameter defines the property used as node sizes.                                                            |
+--------------+------------------------------+----------------+-------------+--------------------------------------------------------------------------------------------------------------------+
| Node Shape   | :class:`tlp.IntegerProperty` | viewShape      | output      | This parameter defines the property used as node shapes.                                                           |
+--------------+------------------------------+----------------+-------------+--------------------------------------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Squarified Tree Map', graph)

  # set any input parameter value if needed
  # params['metric'] = ...
  # params['Aspect Ratio'] = ...
  # params['Treemap Type'] = ...
  # params['Node Size'] = ...
  # params['Node Shape'] = ...

  # either create or get a layout property from the graph to store the result of the algorithm
  resultLayout = graph.getLayoutProperty('resultLayout')
  success = graph.applyLayoutAlgorithm('Squarified Tree Map', resultLayout, params)

  # or store the result of the algorithm in the default Tulip layout property named 'viewLayout'
  success = graph.applyLayoutAlgorithm('Squarified Tree Map', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Stress Majorization (OGDF)
^^^^^^^^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Implements an alternative to force-directed layout which is a distance-based layout realized by the stress majorization approach. 

Parameters
""""""""""

+----------------------------+-------------------------------+---------------------------------------------------------------------------------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------+
| name                       | type                          | default                                                                                     | direction   | description                                                                                                                               |
+============================+===============================+=============================================================================================+=============+===========================================================================================================================================+
| terminationCriterion       | :class:`tlp.StringCollection` | None |br| |br| Values for that parameter: |br| None  |br|  PositionDifference  |br|  Stress | input       | Tells which TERMINATION_CRITERIA should be used.                                                                                          |
+----------------------------+-------------------------------+---------------------------------------------------------------------------------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------+
| fixXCoordinates            | Boolean                       | :const:`False`                                                                              | input       | Tells whether the x coordinates are allowed to be modified or not.                                                                        |
+----------------------------+-------------------------------+---------------------------------------------------------------------------------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------+
| fixYCoordinates            | Boolean                       | :const:`False`                                                                              | input       | Tells whether the y coordinates are allowed to be modified or not.                                                                        |
+----------------------------+-------------------------------+---------------------------------------------------------------------------------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------+
| hasInitialLayout           | Boolean                       | :const:`False`                                                                              | input       | Tells whether the current layout should be used or the initial layout needs to be computed.                                               |
+----------------------------+-------------------------------+---------------------------------------------------------------------------------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------+
| layoutComponentsSeparately | Boolean                       | :const:`False`                                                                              | input       | Sets whether the graph components should be layouted separately or a dummy distance should be used for nodes within different components. |
+----------------------------+-------------------------------+---------------------------------------------------------------------------------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------+
| numberOfIterations         | integer                       | 200                                                                                         | input       | Sets a fixed number of iterations for stress majorization. If the new value is smaller or equal 0 the default value (200) is used.        |
+----------------------------+-------------------------------+---------------------------------------------------------------------------------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------+
| edgeCosts                  | floating point number         | 100                                                                                         | input       | Sets the desired distance between adjacent nodes. If the new value is smaller or equal 0 the default value (100) is used.                 |
+----------------------------+-------------------------------+---------------------------------------------------------------------------------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------+
| useEdgeCostsProperty       | Boolean                       | :const:`False`                                                                              | input       | Tells whether the edge costs are uniform or defined in an edge costs property.                                                            |
+----------------------------+-------------------------------+---------------------------------------------------------------------------------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------+
| edgeCostsProperty          | :class:`tlp.NumericProperty`  | viewMetric                                                                                  | input       | The numeric property that holds the desired cost for each edge.                                                                           |
+----------------------------+-------------------------------+---------------------------------------------------------------------------------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Stress Majorization (OGDF)', graph)

  # set any input parameter value if needed
  # params['terminationCriterion'] = ...
  # params['fixXCoordinates'] = ...
  # params['fixYCoordinates'] = ...
  # params['hasInitialLayout'] = ...
  # params['layoutComponentsSeparately'] = ...
  # params['numberOfIterations'] = ...
  # params['edgeCosts'] = ...
  # params['useEdgeCostsProperty'] = ...
  # params['edgeCostsProperty'] = ...

  # either create or get a layout property from the graph to store the result of the algorithm
  resultLayout = graph.getLayoutProperty('resultLayout')
  success = graph.applyLayoutAlgorithm('Stress Majorization (OGDF)', resultLayout, params)

  # or store the result of the algorithm in the default Tulip layout property named 'viewLayout'
  success = graph.applyLayoutAlgorithm('Stress Majorization (OGDF)', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Sugiyama (OGDF)
^^^^^^^^^^^^^^^

Description
"""""""""""

Implements the classical layout algorithm by Sugiyama, Tagawa, and Toda. It is a layer-based approach for producing upward drawings.

Parameters
""""""""""

+---------------------------------+-------------------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| name                            | type                          | default                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             | direction   | description                                                                                                                                                                                                               |
+=================================+===============================+=====================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================+=============+===========================================================================================================================================================================================================================+
| fails                           | integer                       | 4                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   | input       | The number of times that the number of crossings may not decrease after a complete top-down bottom-up traversal, before a run is terminated.                                                                              |
+---------------------------------+-------------------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| runs                            | integer                       | 15                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  | input       | Determines, how many times the crossing minimization is repeated. Each repetition (except for the first) starts with randomly permuted nodes on each layer. Deterministic behaviour can be achieved by setting runs to 1. |
+---------------------------------+-------------------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| node distance                   | floating point number         | 3                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   | input       | The minimal horizontal distance between two nodes on the same layer.                                                                                                                                                      |
+---------------------------------+-------------------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| layer distance                  | floating point number         | 3                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   | input       | The minimal vertical distance between two nodes on neighboring layers.                                                                                                                                                    |
+---------------------------------+-------------------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| fixed layer distance            | Boolean                       | :const:`False`                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      | input       | If true, the distance between neighboring layers is fixed, otherwise variable (only for FastHierarchyLayout).                                                                                                             |
+---------------------------------+-------------------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| transpose                       | Boolean                       | :const:`True`                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       | input       | If this option is set to true an additional fine tuning step is performed after each traversal, which tries to reduce the total number of crossings by switching adjacent vertices on the same layer.                     |
+---------------------------------+-------------------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| arrangeCCs                      | Boolean                       | :const:`True`                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       | input       | If set to true connected components are laid out separately and the resulting layouts are arranged afterwards using the packer module.                                                                                    |
+---------------------------------+-------------------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| minDistCC                       | floating point number         | 20                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  | input       | Specifies the spacing between connected components of the graph.                                                                                                                                                          |
+---------------------------------+-------------------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| pageRatio                       | floating point number         | 1.0                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 | input       | The page ratio used for packing connected components.                                                                                                                                                                     |
+---------------------------------+-------------------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| alignBaseClasses                | Boolean                       | :const:`False`                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      | input       | Determines if base classes of inheritance hierarchies shall be aligned.                                                                                                                                                   |
+---------------------------------+-------------------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| alignSiblings                   | Boolean                       | :const:`False`                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      | input       | Sets the option alignSiblings.                                                                                                                                                                                            |
+---------------------------------+-------------------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| Ranking                         | :class:`tlp.StringCollection` | LongestPathRanking |br| |br| Values for that parameter: |br| CoffmanGrahamRanking  |istart| (The coffman graham ranking algorithm) |iend|  |br| LongestPathRanking  |istart| (the well-known longest-path ranking algorithm) |iend|  |br| OptimalRanking  |istart| (the LP-based algorithm for computing a node ranking with minimal edge lengths) |iend|                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           | input       | Sets the option for the node ranking (layer assignment).                                                                                                                                                                  |
+---------------------------------+-------------------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| Two-layer crossing minimization | :class:`tlp.StringCollection` | BarycenterHeuristic |br| |br| Values for that parameter: |br| BarycenterHeuristic  |istart| (the barycenter heuristic for 2-layer crossing minimization) |iend|  |br| GreedyInsertHeuristic  |istart| (The greedy-insert heuristic for 2-layer crossing minimization) |iend|  |br| GreedySwitchHeuristic  |istart| (The greedy-switch heuristic for 2-layer crossing minimization) |iend|  |br| MedianHeuristic  |istart| (the median heuristic for 2-layer crossing minimization) |iend|  |br| SiftingHeuristic  |istart| (The sifting heuristic for 2-layer crossing minimization) |iend|  |br| SplitHeuristic  |istart| (the split heuristic for 2-layer crossing minimization) |iend|  |br| GridSiftingHeuristic  |istart| (the grid sifting heuristic for 2-layer crossing minimization) |iend|  |br| GlobalSiftingHeuristic  |istart| (the global sifting heuristic for 2-layer crossing minimization) |iend| | input       | Sets the module option for the two-layer crossing minimization.                                                                                                                                                           |
+---------------------------------+-------------------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| Layout                          | :class:`tlp.StringCollection` | FastHierarchyLayout |br| |br| Values for that parameter: |br| FastHierarchyLayout  |istart| (Coordinate assignment phase for the Sugiyama algorithm by Buchheim et al.) |iend|  |br| FastSimpleHierarchyLayout  |istart| (Coordinate assignment phase for the Sugiyama algorithm by Ulrik Brandes and Boris Koepf) |iend|  |br| OptimalHierarchyLayout  |istart| (The LP-based hierarchy layout algorithm) |iend|                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   | input       | The hierarchy layout module that computes the final layout.                                                                                                                                                               |
+---------------------------------+-------------------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| transpose vertically            | Boolean                       | :const:`True`                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       | input       | Transpose the layout vertically from top to bottom.                                                                                                                                                                       |
+---------------------------------+-------------------------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Sugiyama (OGDF)', graph)

  # set any input parameter value if needed
  # params['fails'] = ...
  # params['runs'] = ...
  # params['node distance'] = ...
  # params['layer distance'] = ...
  # params['fixed layer distance'] = ...
  # params['transpose'] = ...
  # params['arrangeCCs'] = ...
  # params['minDistCC'] = ...
  # params['pageRatio'] = ...
  # params['alignBaseClasses'] = ...
  # params['alignSiblings'] = ...
  # params['Ranking'] = ...
  # params['Two-layer crossing minimization'] = ...
  # params['Layout'] = ...
  # params['transpose vertically'] = ...

  # either create or get a layout property from the graph to store the result of the algorithm
  resultLayout = graph.getLayoutProperty('resultLayout')
  success = graph.applyLayoutAlgorithm('Sugiyama (OGDF)', resultLayout, params)

  # or store the result of the algorithm in the default Tulip layout property named 'viewLayout'
  success = graph.applyLayoutAlgorithm('Sugiyama (OGDF)', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Tile To Rows Packing (OGDF)
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

The tile-to-rows algorithm for packing drawings of connected components.

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Tile To Rows Packing (OGDF)', graph)

  # either create or get a layout property from the graph to store the result of the algorithm
  resultLayout = graph.getLayoutProperty('resultLayout')
  success = graph.applyLayoutAlgorithm('Tile To Rows Packing (OGDF)', resultLayout, params)

  # or store the result of the algorithm in the default Tulip layout property named 'viewLayout'
  success = graph.applyLayoutAlgorithm('Tile To Rows Packing (OGDF)', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Tree Leaf
^^^^^^^^^

Description
"""""""""""

Implements a simple level-based tree layout.

Parameters
""""""""""

+-----------------------+-------------------------------+-----------------------------------------------------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------------------------------+
| name                  | type                          | default                                                                                                                     | direction   | description                                                                                   |
+=======================+===============================+=============================================================================================================================+=============+===============================================================================================+
| node size             | :class:`tlp.SizeProperty`     | viewSize                                                                                                                    | input       | This parameter defines the property used for node sizes.                                      |
+-----------------------+-------------------------------+-----------------------------------------------------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------------------------------+
| orientation           | :class:`tlp.StringCollection` | up to down |br| |br| Values for that parameter: |br| up to down  |br|  down to up  |br|  right to left  |br|  left to right | input       | Choose a desired orientation.                                                                 |
+-----------------------+-------------------------------+-----------------------------------------------------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------------------------------+
| uniform layer spacing | Boolean                       | :const:`True`                                                                                                               | input       | If the layer spacing is uniform, the spacing between two consecutive layers will be the same. |
+-----------------------+-------------------------------+-----------------------------------------------------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------------------------------+
| layer spacing         | floating point number         | 64.                                                                                                                         | input       | This parameter enables to set up the minimum space between two layers in the drawing.         |
+-----------------------+-------------------------------+-----------------------------------------------------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------------------------------+
| node spacing          | floating point number         | 18.                                                                                                                         | input       | This parameter enables to set up the minimum space between two nodes in the same layer.       |
+-----------------------+-------------------------------+-----------------------------------------------------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Tree Leaf', graph)

  # set any input parameter value if needed
  # params['node size'] = ...
  # params['orientation'] = ...
  # params['uniform layer spacing'] = ...
  # params['layer spacing'] = ...
  # params['node spacing'] = ...

  # either create or get a layout property from the graph to store the result of the algorithm
  resultLayout = graph.getLayoutProperty('resultLayout')
  success = graph.applyLayoutAlgorithm('Tree Leaf', resultLayout, params)

  # or store the result of the algorithm in the default Tulip layout property named 'viewLayout'
  success = graph.applyLayoutAlgorithm('Tree Leaf', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Tree Radial
^^^^^^^^^^^

Description
"""""""""""

Implements the radial tree layout algorithm first published as: |br| T. J. Jankun-Kelly, Kwan-Liu Ma  |bstart| MoireGraphs: Radial Focus+Context Visualization and Interaction for Graphs with Visual Nodes |bend|  Proc. IEEE Symposium on Information Visualization, INFOVIS pages 59--66 (2003).

Parameters
""""""""""

+---------------+---------------------------+-----------+-------------+-----------------------------------------------------------------------------------------+
| name          | type                      | default   | direction   | description                                                                             |
+===============+===========================+===========+=============+=========================================================================================+
| node size     | :class:`tlp.SizeProperty` | viewSize  | input       | This parameter defines the property used for node sizes.                                |
+---------------+---------------------------+-----------+-------------+-----------------------------------------------------------------------------------------+
| layer spacing | floating point number     | 64.       | input       | This parameter enables to set up the minimum space between two layers in the drawing.   |
+---------------+---------------------------+-----------+-------------+-----------------------------------------------------------------------------------------+
| node spacing  | floating point number     | 18.       | input       | This parameter enables to set up the minimum space between two nodes in the same layer. |
+---------------+---------------------------+-----------+-------------+-----------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Tree Radial', graph)

  # set any input parameter value if needed
  # params['node size'] = ...
  # params['layer spacing'] = ...
  # params['node spacing'] = ...

  # either create or get a layout property from the graph to store the result of the algorithm
  resultLayout = graph.getLayoutProperty('resultLayout')
  success = graph.applyLayoutAlgorithm('Tree Radial', resultLayout, params)

  # or store the result of the algorithm in the default Tulip layout property named 'viewLayout'
  success = graph.applyLayoutAlgorithm('Tree Radial', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Upward Planarization (OGDF)
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Implements an alternative to the classical Sugiyama approach. It adapts the planarization approach for hierarchical graphs and produces significantly less crossings than Sugiyama layout.

Parameters
""""""""""

+-----------+---------+----------------+-------------+-------------------------------------------+
| name      | type    | default        | direction   | description                               |
+===========+=========+================+=============+===========================================+
| transpose | Boolean | :const:`False` | input       | If true, transpose the layout vertically. |
+-----------+---------+----------------+-------------+-------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Upward Planarization (OGDF)', graph)

  # set any input parameter value if needed
  # params['transpose'] = ...

  # either create or get a layout property from the graph to store the result of the algorithm
  resultLayout = graph.getLayoutProperty('resultLayout')
  success = graph.applyLayoutAlgorithm('Upward Planarization (OGDF)', resultLayout, params)

  # or store the result of the algorithm in the default Tulip layout property named 'viewLayout'
  success = graph.applyLayoutAlgorithm('Upward Planarization (OGDF)', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Visibility (OGDF)
^^^^^^^^^^^^^^^^^

Description
"""""""""""

Implements a simple upward drawing algorithm based on visibility representations (horizontal segments for nodes, vectical segments for edges).

Parameters
""""""""""

+-----------------------+---------+----------------+-------------+-------------------------------------------+
| name                  | type    | default        | direction   | description                               |
+=======================+=========+================+=============+===========================================+
| minimum grid distance | integer | 1              | input       | The minimum grid distance.                |
+-----------------------+---------+----------------+-------------+-------------------------------------------+
| transpose             | Boolean | :const:`False` | input       | If true, transpose the layout vertically. |
+-----------------------+---------+----------------+-------------+-------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Visibility (OGDF)', graph)

  # set any input parameter value if needed
  # params['minimum grid distance'] = ...
  # params['transpose'] = ...

  # either create or get a layout property from the graph to store the result of the algorithm
  resultLayout = graph.getLayoutProperty('resultLayout')
  success = graph.applyLayoutAlgorithm('Visibility (OGDF)', resultLayout, params)

  # or store the result of the algorithm in the default Tulip layout property named 'viewLayout'
  success = graph.applyLayoutAlgorithm('Visibility (OGDF)', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Measure
-------

.. _doublepluginsdoc:

To call these plugins, you must use the :meth:`tlp.Graph.applyDoubleAlgorithm` method. See also :ref:`Calling a property algorithm on a graph <callPropertyAlgorithm>` for more details.

Betweenness Centrality
^^^^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Computes the betweenness centrality.

Parameters
""""""""""

+----------+---------+----------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| name     | type    | default        | direction   | description                                                                                                                                                                                                                                                                                                                          |
+==========+=========+================+=============+======================================================================================================================================================================================================================================================================================================================================+
| directed | Boolean | :const:`False` | input       | Indicates if the graph should be considered as directed or not.                                                                                                                                                                                                                                                                      |
+----------+---------+----------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| norm     | Boolean | :const:`False` | input       | If true the node measure will be normalized |br|  - if not directed : m(n) = 2*c(n) / (#V - 1)(#V - 2) |br|  - if directed     : m(n) = c(n) / (#V - 1)(#V - 2) |br| If true the edge measure will be normalized |br|  - if not directed : m(e) = 2*c(e) / (#V / 2)(#V / 2) |br|  - if directed     : m(e) = c(e) / (#V / 2)(#V / 2) |
+----------+---------+----------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Betweenness Centrality', graph)

  # set any input parameter value if needed
  # params['directed'] = ...
  # params['norm'] = ...

  # either create or get a double property from the graph to store the result of the algorithm
  resultMetric = graph.getDoubleProperty('resultMetric')
  success = graph.applyDoubleAlgorithm('Betweenness Centrality', resultMetric, params)

  # or store the result of the algorithm in the default Tulip metric property named 'viewMetric'
  success = graph.applyDoubleAlgorithm('Betweenness Centrality', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Biconnected Component
^^^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Implements a biconnected component decomposition.It assigns the same value to all the edges in the same component.

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Biconnected Component', graph)

  # either create or get a double property from the graph to store the result of the algorithm
  resultMetric = graph.getDoubleProperty('resultMetric')
  success = graph.applyDoubleAlgorithm('Biconnected Component', resultMetric, params)

  # or store the result of the algorithm in the default Tulip metric property named 'viewMetric'
  success = graph.applyDoubleAlgorithm('Biconnected Component', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Cluster
^^^^^^^

Description
"""""""""""

Computes the Cluster metric as described in |br|  |bstart| Software component capture using graph clustering |bend| , Y. Chiricota. F.Jourdan, an G.Melancon, IWPC (2002).

Parameters
""""""""""

+--------+------------------+-----------+-------------+--------------------------------------+
| name   | type             |   default | direction   | description                          |
+========+==================+===========+=============+======================================+
| depth  | unsigned integer |         1 | input       | Maximal depth of a computed cluster. |
+--------+------------------+-----------+-------------+--------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Cluster', graph)

  # set any input parameter value if needed
  # params['depth'] = ...

  # either create or get a double property from the graph to store the result of the algorithm
  resultMetric = graph.getDoubleProperty('resultMetric')
  success = graph.applyDoubleAlgorithm('Cluster', resultMetric, params)

  # or store the result of the algorithm in the default Tulip metric property named 'viewMetric'
  success = graph.applyDoubleAlgorithm('Cluster', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Connected Component
^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Implements a decompostion in connected components.                     This algorithm assigns to each node a value defined as following: if two nodes are in the same                     connected component they have the same value else they have a different value. Edges get the value of their source node.

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Connected Component', graph)

  # either create or get a double property from the graph to store the result of the algorithm
  resultMetric = graph.getDoubleProperty('resultMetric')
  success = graph.applyDoubleAlgorithm('Connected Component', resultMetric, params)

  # or store the result of the algorithm in the default Tulip metric property named 'viewMetric'
  success = graph.applyDoubleAlgorithm('Connected Component', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Convolution
^^^^^^^^^^^

Description
"""""""""""

Discretization and filtering of the distribution of a node metric using a convolution.

Parameters
""""""""""

+--------+------------------------------+------------+-------------+-----------------------------------+
| name   | type                         | default    | direction   | description                       |
+========+==============================+============+=============+===================================+
| metric | :class:`tlp.NumericProperty` | viewMetric | input       | An existing node metric property. |
+--------+------------------------------+------------+-------------+-----------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Convolution', graph)

  # set any input parameter value if needed
  # params['metric'] = ...

  # either create or get a double property from the graph to store the result of the algorithm
  resultMetric = graph.getDoubleProperty('resultMetric')
  success = graph.applyDoubleAlgorithm('Convolution', resultMetric, params)

  # or store the result of the algorithm in the default Tulip metric property named 'viewMetric'
  success = graph.applyDoubleAlgorithm('Convolution', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Dag Level
^^^^^^^^^

Description
"""""""""""

Implements a DAG layer decomposition.

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Dag Level', graph)

  # either create or get a double property from the graph to store the result of the algorithm
  resultMetric = graph.getDoubleProperty('resultMetric')
  success = graph.applyDoubleAlgorithm('Dag Level', resultMetric, params)

  # or store the result of the algorithm in the default Tulip metric property named 'viewMetric'
  success = graph.applyDoubleAlgorithm('Dag Level', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Degree
^^^^^^

Description
"""""""""""

Assigns its degree to each node.

Parameters
""""""""""

+--------+-------------------------------+----------------------------------------------------------------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| name   | type                          | default                                                                    | direction   | description                                                                                                                                                                                                             |
+========+===============================+============================================================================+=============+=========================================================================================================================================================================================================================+
| type   | :class:`tlp.StringCollection` | InOut |br| |br| Values for that parameter: |br| InOut  |br|  In  |br|  Out | input       | Type of degree to compute (in/out/inout).                                                                                                                                                                               |
+--------+-------------------------------+----------------------------------------------------------------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| metric | :class:`tlp.NumericProperty`  |                                                                            | input       | The weighted degree of a node is the sum of weights of all its in/out/inout edges. If no metric is specified, using a uniform metric value of 1 for all edges returns the usual degree for nodes (number of neighbors). |
+--------+-------------------------------+----------------------------------------------------------------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| norm   | Boolean                       | :const:`False`                                                             | input       | If true, the measure is normalized in the following way. |ulstart|  |listart| Unweighted case: m(n) = deg(n) / (#V - 1) |liend|   |listart| Weighted case: m(n) = deg_w(n) / [(sum(e_w)/#E)(#V - 1)]  |liend|  |ulend|  |
+--------+-------------------------------+----------------------------------------------------------------------------+-------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Degree', graph)

  # set any input parameter value if needed
  # params['type'] = ...
  # params['metric'] = ...
  # params['norm'] = ...

  # either create or get a double property from the graph to store the result of the algorithm
  resultMetric = graph.getDoubleProperty('resultMetric')
  success = graph.applyDoubleAlgorithm('Degree', resultMetric, params)

  # or store the result of the algorithm in the default Tulip metric property named 'viewMetric'
  success = graph.applyDoubleAlgorithm('Degree', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Depth
^^^^^

Description
"""""""""""

For each node n on an acyclic graph,it computes the maximum path length between n and the other node. |br|  |bstart| The graph must be acyclic |bend| .

Parameters
""""""""""

+-------------+------------------------------+-----------+-------------+----------------------------------------------------------+
| name        | type                         | default   | direction   | description                                              |
+=============+==============================+===========+=============+==========================================================+
| edge weight | :class:`tlp.NumericProperty` |           | input       | This parameter defines the metric used for edge weights. |
+-------------+------------------------------+-----------+-------------+----------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Depth', graph)

  # set any input parameter value if needed
  # params['edge weight'] = ...

  # either create or get a double property from the graph to store the result of the algorithm
  resultMetric = graph.getDoubleProperty('resultMetric')
  success = graph.applyDoubleAlgorithm('Depth', resultMetric, params)

  # or store the result of the algorithm in the default Tulip metric property named 'viewMetric'
  success = graph.applyDoubleAlgorithm('Depth', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Eccentricity
^^^^^^^^^^^^

Description
"""""""""""

Computes the eccentricity/closeness centrality of each node. |br|  |bstart| Eccentricity |bend|  is the maximum distance to go from a node to all others. In this version the Eccentricity value can be normalized (1 means that a node is one of the most eccentric in the network, 0 means that a node is on the centers of the network). |br|  |bstart| Closeness Centrality |bend|  is the mean of shortest-paths lengths from a node to others. The normalized values are computed using the reciprocal of the sum of these distances.

Parameters
""""""""""

+----------------------+---------+----------------+-------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| name                 | type    | default        | direction   | description                                                                                                                                                                                                                                                                                                   |
+======================+=========+================+=============+===============================================================================================================================================================================================================================================================================================================+
| closeness centrality | Boolean | :const:`False` | input       | If true, the closeness centrality is computed (i.e. the average distance from a node to all others).                                                                                                                                                                                                          |
+----------------------+---------+----------------+-------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| norm                 | Boolean | :const:`True`  | input       | If true, the returned values are normalized. For the closeness centrality, the reciprocal of the sum of distances is returned. The eccentricity values are divided by the graph diameter.  |bstart|  Warning :  |bend|  The normalized eccentricity values sould be computed on a (strongly) connected graph. |
+----------------------+---------+----------------+-------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| directed             | Boolean | :const:`False` | input       | If true, the graph is considered directed.                                                                                                                                                                                                                                                                    |
+----------------------+---------+----------------+-------------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Eccentricity', graph)

  # set any input parameter value if needed
  # params['closeness centrality'] = ...
  # params['norm'] = ...
  # params['directed'] = ...

  # either create or get a double property from the graph to store the result of the algorithm
  resultMetric = graph.getDoubleProperty('resultMetric')
  success = graph.applyDoubleAlgorithm('Eccentricity', resultMetric, params)

  # or store the result of the algorithm in the default Tulip metric property named 'viewMetric'
  success = graph.applyDoubleAlgorithm('Eccentricity', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Id
^^

Description
"""""""""""

Assigns their Tulip id to nodes and edges.

Parameters
""""""""""

+--------+-------------------------------+-------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------+
| name   | type                          | default                                                                       | direction   | description                                                           |
+========+===============================+===============================================================================+=============+=======================================================================+
| target | :class:`tlp.StringCollection` | both |br| |br| Values for that parameter: |br| both  |br|  nodes  |br|  edges | input       | Whether the id is copied only for nodes, only for edges, or for both. |
+--------+-------------------------------+-------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Id', graph)

  # set any input parameter value if needed
  # params['target'] = ...

  # either create or get a double property from the graph to store the result of the algorithm
  resultMetric = graph.getDoubleProperty('resultMetric')
  success = graph.applyDoubleAlgorithm('Id', resultMetric, params)

  # or store the result of the algorithm in the default Tulip metric property named 'viewMetric'
  success = graph.applyDoubleAlgorithm('Id', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

K-Cores
^^^^^^^

Description
"""""""""""

Node partitioning measure based on the K-core decomposition of a graph. |br| K-cores were first introduced in: |br|  |bstart| Network structure and minimum degree |bend| , S. B. Seidman, Social Networks 5:269-287 (1983). |br| This is a method for simplifying a graph topology which helps in analysis and visualization of social networks. |br|  |bstart| Note |bend| : use the default parameters to compute simple K-Cores (undirected and unweighted).

Parameters
""""""""""

+--------+-------------------------------+----------------------------------------------------------------------------+-------------+-------------------------------------------------------------------------+
| name   | type                          | default                                                                    | direction   | description                                                             |
+========+===============================+============================================================================+=============+=========================================================================+
| type   | :class:`tlp.StringCollection` | InOut |br| |br| Values for that parameter: |br| InOut  |br|  In  |br|  Out | input       | This parameter indicates the direction used to compute K-Cores values.  |
+--------+-------------------------------+----------------------------------------------------------------------------+-------------+-------------------------------------------------------------------------+
| metric | :class:`tlp.NumericProperty`  |                                                                            | input       | An existing edge metric property, used to specify the weights of edges. |
+--------+-------------------------------+----------------------------------------------------------------------------+-------------+-------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('K-Cores', graph)

  # set any input parameter value if needed
  # params['type'] = ...
  # params['metric'] = ...

  # either create or get a double property from the graph to store the result of the algorithm
  resultMetric = graph.getDoubleProperty('resultMetric')
  success = graph.applyDoubleAlgorithm('K-Cores', resultMetric, params)

  # or store the result of the algorithm in the default Tulip metric property named 'viewMetric'
  success = graph.applyDoubleAlgorithm('K-Cores', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Leaf
^^^^

Description
"""""""""""

Computes the number of leaves in the subtree induced by each node. |br|  |bstart| The graph must be acyclic |bend| .

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Leaf', graph)

  # either create or get a double property from the graph to store the result of the algorithm
  resultMetric = graph.getDoubleProperty('resultMetric')
  success = graph.applyDoubleAlgorithm('Leaf', resultMetric, params)

  # or store the result of the algorithm in the default Tulip metric property named 'viewMetric'
  success = graph.applyDoubleAlgorithm('Leaf', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Link Communities
^^^^^^^^^^^^^^^^

Description
"""""""""""

Edges partitioning measure used for community detection. |br| It is an implementation of a fuzzy clustering procedure. First introduced in : |br|   |bstart| Link communities reveal multiscale complexity in networks |bend| , Ahn, Y.Y. and Bagrow, J.P. and Lehmann, S., Nature vol:466, 761--764 (2010)

Parameters
""""""""""

+-----------------+------------------------------+---------------+-------------+------------------------------------------------------------------------------------+
| name            | type                         | default       | direction   | description                                                                        |
+=================+==============================+===============+=============+====================================================================================+
| metric          | :class:`tlp.NumericProperty` |               | input       | An existing edge metric property.                                                  |
+-----------------+------------------------------+---------------+-------------+------------------------------------------------------------------------------------+
| Group isthmus   | Boolean                      | :const:`True` | input       | This parameter indicates whether the single-link clusters should be merged or not. |
+-----------------+------------------------------+---------------+-------------+------------------------------------------------------------------------------------+
| Number of steps | unsigned integer             | 200           | input       | This parameter indicates the number of thresholds to be compared.                  |
+-----------------+------------------------------+---------------+-------------+------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Link Communities', graph)

  # set any input parameter value if needed
  # params['metric'] = ...
  # params['Group isthmus'] = ...
  # params['Number of steps'] = ...

  # either create or get a double property from the graph to store the result of the algorithm
  resultMetric = graph.getDoubleProperty('resultMetric')
  success = graph.applyDoubleAlgorithm('Link Communities', resultMetric, params)

  # or store the result of the algorithm in the default Tulip metric property named 'viewMetric'
  success = graph.applyDoubleAlgorithm('Link Communities', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Louvain
^^^^^^^

Description
"""""""""""

Nodes partitioning measure used for community detection.This is an implementation of the Louvain clustering algorithm first published as: |br|  |bstart| Fast unfolding of communities in large networks |bend| , Blondel, V.D. and Guillaume, J.L. and Lambiotte, R. and Lefebvre, E., Journal of Statistical Mechanics: Theory and Experiment, P10008 (2008).

Parameters
""""""""""

+-----------+------------------------------+-----------+-------------+------------------------------------------------------------------------------------------------------------------------+
| name      | type                         | default   | direction   | description                                                                                                            |
+===========+==============================+===========+=============+========================================================================================================================+
| metric    | :class:`tlp.NumericProperty` |           | input       | An existing edge weight metric property. If it is not defined all edges have a weight of 1.0.                          |
+-----------+------------------------------+-----------+-------------+------------------------------------------------------------------------------------------------------------------------+
| precision | floating point number        | 0.000001  | input       | A given pass stops when the modularity is increased by less than precision. Default value is  |bstart| 0.000001 |bend| |
+-----------+------------------------------+-----------+-------------+------------------------------------------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Louvain', graph)

  # set any input parameter value if needed
  # params['metric'] = ...
  # params['precision'] = ...

  # either create or get a double property from the graph to store the result of the algorithm
  resultMetric = graph.getDoubleProperty('resultMetric')
  success = graph.applyDoubleAlgorithm('Louvain', resultMetric, params)

  # or store the result of the algorithm in the default Tulip metric property named 'viewMetric'
  success = graph.applyDoubleAlgorithm('Louvain', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

MCL Clustering
^^^^^^^^^^^^^^

Description
"""""""""""

Nodes partitioning measure of Markov Cluster algorithm |br| used for community detection.This is an implementation of the MCL algorithm first published as: |br|  |bstart| Graph Clustering by Flow Simulation |bend| , Stijn van Dongen PhD Thesis, University of Utrecht (2000).

Parameters
""""""""""

+---------+------------------------------+-----------+-------------+---------------------------------------------------------------------------------+
| name    | type                         | default   | direction   | description                                                                     |
+=========+==============================+===========+=============+=================================================================================+
| inflate | floating point number        | 2.        | input       | Determines the random walk length at each step.                                 |
+---------+------------------------------+-----------+-------------+---------------------------------------------------------------------------------+
| weights | :class:`tlp.NumericProperty` |           | input       | Edge weights to use.                                                            |
+---------+------------------------------+-----------+-------------+---------------------------------------------------------------------------------+
| pruning | unsigned integer             | 5         | input       | Determines, for each node, the number of strongest link kept at each iteration. |
+---------+------------------------------+-----------+-------------+---------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('MCL Clustering', graph)

  # set any input parameter value if needed
  # params['inflate'] = ...
  # params['weights'] = ...
  # params['pruning'] = ...

  # either create or get a double property from the graph to store the result of the algorithm
  resultMetric = graph.getDoubleProperty('resultMetric')
  success = graph.applyDoubleAlgorithm('MCL Clustering', resultMetric, params)

  # or store the result of the algorithm in the default Tulip metric property named 'viewMetric'
  success = graph.applyDoubleAlgorithm('MCL Clustering', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Node
^^^^

Description
"""""""""""

Computes the number of nodes in the subtree induced by each node. |br|  |bstart| The graph must be acyclic |bend| .

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Node', graph)

  # either create or get a double property from the graph to store the result of the algorithm
  resultMetric = graph.getDoubleProperty('resultMetric')
  success = graph.applyDoubleAlgorithm('Node', resultMetric, params)

  # or store the result of the algorithm in the default Tulip metric property named 'viewMetric'
  success = graph.applyDoubleAlgorithm('Node', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Page Rank
^^^^^^^^^

Description
"""""""""""

Nodes measure used for links analysis. |br| First designed by Larry Page and Sergey Brin, it is a link analysis algorithm that assigns a measure to each node of an 'hyperlinked' graph.

Parameters
""""""""""

+----------+-----------------------+---------------+-------------+-----------------------------------------------------------------+
| name     | type                  | default       | direction   | description                                                     |
+==========+=======================+===============+=============+=================================================================+
| d        | floating point number | 0.85          | input       | Enables to choose a damping factor in ]0,1[.                    |
+----------+-----------------------+---------------+-------------+-----------------------------------------------------------------+
| directed | Boolean               | :const:`True` | input       | Indicates if the graph should be considered as directed or not. |
+----------+-----------------------+---------------+-------------+-----------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Page Rank', graph)

  # set any input parameter value if needed
  # params['d'] = ...
  # params['directed'] = ...

  # either create or get a double property from the graph to store the result of the algorithm
  resultMetric = graph.getDoubleProperty('resultMetric')
  success = graph.applyDoubleAlgorithm('Page Rank', resultMetric, params)

  # or store the result of the algorithm in the default Tulip metric property named 'viewMetric'
  success = graph.applyDoubleAlgorithm('Page Rank', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Path Length
^^^^^^^^^^^

Description
"""""""""""

Assigns to each node the number of paths that goes through it. |br|  |bstart| The graph must be acyclic |bend| .

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Path Length', graph)

  # either create or get a double property from the graph to store the result of the algorithm
  resultMetric = graph.getDoubleProperty('resultMetric')
  success = graph.applyDoubleAlgorithm('Path Length', resultMetric, params)

  # or store the result of the algorithm in the default Tulip metric property named 'viewMetric'
  success = graph.applyDoubleAlgorithm('Path Length', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Random metric
^^^^^^^^^^^^^

Description
"""""""""""

Assigns random values to nodes and edges.

Parameters
""""""""""

+--------+-------------------------------+-------------------------------------------------------------------------------+-------------+-------------------------------------------------------------------------+
| name   | type                          | default                                                                       | direction   | description                                                             |
+========+===============================+===============================================================================+=============+=========================================================================+
| target | :class:`tlp.StringCollection` | both |br| |br| Values for that parameter: |br| both  |br|  nodes  |br|  edges | input       | Whether metric is computed only for nodes, only for edges, or for both. |
+--------+-------------------------------+-------------------------------------------------------------------------------+-------------+-------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Random metric', graph)

  # set any input parameter value if needed
  # params['target'] = ...

  # either create or get a double property from the graph to store the result of the algorithm
  resultMetric = graph.getDoubleProperty('resultMetric')
  success = graph.applyDoubleAlgorithm('Random metric', resultMetric, params)

  # or store the result of the algorithm in the default Tulip metric property named 'viewMetric'
  success = graph.applyDoubleAlgorithm('Random metric', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Strahler
^^^^^^^^

Description
"""""""""""

Computes the Strahler numbers.This is an implementation of the Strahler numbers computation, first published as: |br|  |bstart| Hypsomic analysis of erosional topography |bend| , A.N. Strahler, Bulletin Geological Society of America 63,pages 1117-1142 (1952). |br| Extended to graphs in : |br|  |bstart| Using Strahler numbers for real time visual exploration of huge graphs |bend| , D. Auber, ICCVG, International Conference on Computer Vision and Graphics, pages 56-69 (2002)

Parameters
""""""""""

+-----------+-------------------------------+--------------------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| name      | type                          | default                                                                                    | direction   | description                                                                                                                                                                                                                                   |
+===========+===============================+============================================================================================+=============+===============================================================================================================================================================================================================================================+
| All nodes | Boolean                       | :const:`False`                                                                             | input       | If true, for each node the Strahler number is computed from a spanning tree having that node as root: complexity o(n^2). If false the Strahler number is computed from a spanning tree having the heuristicly estimated graph center as root. |
+-----------+-------------------------------+--------------------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| Type      | :class:`tlp.StringCollection` | all |br| |br| Values for that parameter: |br| all  |br|  ramification  |br|  nested cycles | input       | Sets the type of computation.                                                                                                                                                                                                                 |
+-----------+-------------------------------+--------------------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Strahler', graph)

  # set any input parameter value if needed
  # params['All nodes'] = ...
  # params['Type'] = ...

  # either create or get a double property from the graph to store the result of the algorithm
  resultMetric = graph.getDoubleProperty('resultMetric')
  success = graph.applyDoubleAlgorithm('Strahler', resultMetric, params)

  # or store the result of the algorithm in the default Tulip metric property named 'viewMetric'
  success = graph.applyDoubleAlgorithm('Strahler', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Strength
^^^^^^^^

Description
"""""""""""

Computes the Strength metric described in |br|  |bstart| Software component capture using graph clustering |bend| , Y. Chiricota. F.Jourdan, an G.Melancon, IWPC (2002).

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Strength', graph)

  # either create or get a double property from the graph to store the result of the algorithm
  resultMetric = graph.getDoubleProperty('resultMetric')
  success = graph.applyDoubleAlgorithm('Strength', resultMetric, params)

  # or store the result of the algorithm in the default Tulip metric property named 'viewMetric'
  success = graph.applyDoubleAlgorithm('Strength', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Strength Clustering
^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Implements a single-linkage clustering. The similarity measure used here is the Strength Metric computed on edges. The best threshold is found using MQ Quality Measure. See : |br|  |bstart| Software component capture using graph clustering |bend| , Y. Chiricota. F.Jourdan, an G.Melancon, IWPC (2002).

Parameters
""""""""""

+--------+------------------------------+-----------+-------------+--------------------------------------------------------------------------------------------------------------------------------+
| name   | type                         | default   | direction   | description                                                                                                                    |
+========+==============================+===========+=============+================================================================================================================================+
| metric | :class:`tlp.NumericProperty` |           | input       | Metric used in order to multiply strength metric computed values.If one is given, the complexity is O(n log(n)), O(n) neither. |
+--------+------------------------------+-----------+-------------+--------------------------------------------------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Strength Clustering', graph)

  # set any input parameter value if needed
  # params['metric'] = ...

  # either create or get a double property from the graph to store the result of the algorithm
  resultMetric = graph.getDoubleProperty('resultMetric')
  success = graph.applyDoubleAlgorithm('Strength Clustering', resultMetric, params)

  # or store the result of the algorithm in the default Tulip metric property named 'viewMetric'
  success = graph.applyDoubleAlgorithm('Strength Clustering', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Strongly Connected Component
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Implements a strongly connected components decomposition.

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Strongly Connected Component', graph)

  # either create or get a double property from the graph to store the result of the algorithm
  resultMetric = graph.getDoubleProperty('resultMetric')
  success = graph.applyDoubleAlgorithm('Strongly Connected Component', resultMetric, params)

  # or store the result of the algorithm in the default Tulip metric property named 'viewMetric'
  success = graph.applyDoubleAlgorithm('Strongly Connected Component', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Welsh & Powell
^^^^^^^^^^^^^^

Description
"""""""""""

Nodes coloring measure, |br| values assigned to adjacent nodes are always different.

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Welsh & Powell', graph)

  # either create or get a double property from the graph to store the result of the algorithm
  resultMetric = graph.getDoubleProperty('resultMetric')
  success = graph.applyDoubleAlgorithm('Welsh & Powell', resultMetric, params)

  # or store the result of the algorithm in the default Tulip metric property named 'viewMetric'
  success = graph.applyDoubleAlgorithm('Welsh & Powell', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Resizing
--------

.. _sizepluginsdoc:

To call these plugins, you must use the :meth:`tlp.Graph.applySizeAlgorithm` method. See also :ref:`Calling a property algorithm on a graph <callPropertyAlgorithm>` for more details.

Auto Sizing
^^^^^^^^^^^

Description
"""""""""""

Resize the nodes and edges of a graph so that the graph gets easy to read. The size of a node will depend on the number of its sons.

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Auto Sizing', graph)

  # either create or get a size property from the graph to store the result of the algorithm
  resultSize = graph.getSizeProperty('resultSize')
  success = graph.applySizeAlgorithm('Auto Sizing', resultSize, params)

  # or store the result of the algorithm in the default Tulip size property named 'viewSize'
  success = graph.applySizeAlgorithm('Auto Sizing', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Size Mapping
^^^^^^^^^^^^

Description
"""""""""""

Maps the sizes of the graph elements onto the values of a given numeric property.

Parameters
""""""""""

+-------------------+-------------------------------+------------------------------------------------------------------------------------------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| name              | type                          | default                                                                                              | direction   | description                                                                                                                                                                                                                                                                                                                                      |
+===================+===============================+======================================================================================================+=============+==================================================================================================================================================================================================================================================================================================================================================+
| property          | :class:`tlp.NumericProperty`  | viewMetric                                                                                           | input       | Input metric whose values will be mapped to sizes.                                                                                                                                                                                                                                                                                               |
+-------------------+-------------------------------+------------------------------------------------------------------------------------------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| input             | :class:`tlp.SizeProperty`     | viewSize                                                                                             | input       | If not all dimensions (width, height, depth) are checked below, the dimensions not computed are copied from this property.                                                                                                                                                                                                                       |
+-------------------+-------------------------------+------------------------------------------------------------------------------------------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| width             | Boolean                       | :const:`True`                                                                                        | input       | Each checked dimension is adjusted to represent property, each unchecked dimension is copied from input.                                                                                                                                                                                                                                         |
+-------------------+-------------------------------+------------------------------------------------------------------------------------------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| height            | Boolean                       | :const:`True`                                                                                        | input       | Each checked dimension is adjusted to represent property, each unchecked dimension is copied from input.                                                                                                                                                                                                                                         |
+-------------------+-------------------------------+------------------------------------------------------------------------------------------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| depth             | Boolean                       | :const:`False`                                                                                       | input       | Each checked dimension is adjusted to represent property, each unchecked dimension is copied from input.                                                                                                                                                                                                                                         |
+-------------------+-------------------------------+------------------------------------------------------------------------------------------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| min size          | floating point number         | 1                                                                                                    | input       | Gives the minimum value of the range of computed sizes.                                                                                                                                                                                                                                                                                          |
+-------------------+-------------------------------+------------------------------------------------------------------------------------------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| max size          | floating point number         | 10                                                                                                   | input       | Gives the maximum value of the range of computed sizes.                                                                                                                                                                                                                                                                                          |
+-------------------+-------------------------------+------------------------------------------------------------------------------------------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| type              | Boolean                       | :const:`True`                                                                                        | input       | Type of mapping. |ulstart|  |listart| true: linear mapping (min value of property is mapped to min size, max to max size, and a linear interpolation is used in between.) |liend|  |listart| false: uniform quantification (the values of property are sorted, and the same size increment is used between consecutive values). |liend|  |ulend| |
+-------------------+-------------------------------+------------------------------------------------------------------------------------------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| node/edge         | Boolean                       | :const:`True`                                                                                        | input       | If true the algorithm will compute the size of nodes else it will compute the size of edges: |ulstart|  |listart| true: node size |liend|  |listart| false: edge size |liend|  |ulend|                                                                                                                                                           |
+-------------------+-------------------------------+------------------------------------------------------------------------------------------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| area proportional | :class:`tlp.StringCollection` | Area Proportional |br| |br| Values for that parameter: |br| Area Proportional  |br|  Quadratic/Cubic | input       | The mapping can either be area/volume proportional, or square/cubic;i.e. the areas/volumes will be proportional, or the dimensions (width, height and depth) will be.                                                                                                                                                                            |
+-------------------+-------------------------------+------------------------------------------------------------------------------------------------------+-------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Size Mapping', graph)

  # set any input parameter value if needed
  # params['property'] = ...
  # params['input'] = ...
  # params['width'] = ...
  # params['height'] = ...
  # params['depth'] = ...
  # params['min size'] = ...
  # params['max size'] = ...
  # params['type'] = ...
  # params['node/edge'] = ...
  # params['area proportional'] = ...

  # either create or get a size property from the graph to store the result of the algorithm
  resultSize = graph.getSizeProperty('resultSize')
  success = graph.applySizeAlgorithm('Size Mapping', resultSize, params)

  # or store the result of the algorithm in the default Tulip size property named 'viewSize'
  success = graph.applySizeAlgorithm('Size Mapping', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Selection
---------

.. _booleanpluginsdoc:

To call these plugins, you must use the :meth:`tlp.Graph.applyBooleanAlgorithm` method. See also :ref:`Calling a property algorithm on a graph <callPropertyAlgorithm>` for more details.

Induced Sub-Graph
^^^^^^^^^^^^^^^^^

Description
"""""""""""

Selects all the nodes/edges of the subgraph induced by a set of selected nodes.

Parameters
""""""""""

+-----------+------------------------------+----------------+-------------+--------------------------------------------------------------------------------------------------+
| name      | type                         | default        | direction   | description                                                                                      |
+===========+==============================+================+=============+==================================================================================================+
| Nodes     | :class:`tlp.BooleanProperty` | viewSelection  | input       | Set of nodes from which the induced sub-graph is computed.                                       |
+-----------+------------------------------+----------------+-------------+--------------------------------------------------------------------------------------------------+
| Use edges | Boolean                      | :const:`False` | input       | If true, source and target nodes of selected edges will also be added in the input set of nodes. |
+-----------+------------------------------+----------------+-------------+--------------------------------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Induced Sub-Graph', graph)

  # set any input parameter value if needed
  # params['Nodes'] = ...
  # params['Use edges'] = ...

  # either create or get a boolean property from the graph to store the result of the algorithm
  resultSelection = graph.getBooleanProperty('resultSelection')
  success = graph.applyBooleanAlgorithm('Induced Sub-Graph', resultSelection, params)

  # or store the result of the algorithm in the default Tulip boolean property named 'viewSelection'
  success = graph.applyBooleanAlgorithm('Induced Sub-Graph', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Kruskal
^^^^^^^

Description
"""""""""""

Implements the classical Kruskal algorithm to select a minimum spanning tree in a connected graph.Only works on undirected graphs, (ie. the orientation of edges is omitted).

Parameters
""""""""""

+-------------+------------------------------+------------+-------------+-------------------------------------+
| name        | type                         | default    | direction   | description                         |
+=============+==============================+============+=============+=====================================+
| edge weight | :class:`tlp.NumericProperty` | viewMetric | input       | Metric containing the edge weights. |
+-------------+------------------------------+------------+-------------+-------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Kruskal', graph)

  # set any input parameter value if needed
  # params['edge weight'] = ...

  # either create or get a boolean property from the graph to store the result of the algorithm
  resultSelection = graph.getBooleanProperty('resultSelection')
  success = graph.applyBooleanAlgorithm('Kruskal', resultSelection, params)

  # or store the result of the algorithm in the default Tulip boolean property named 'viewSelection'
  success = graph.applyBooleanAlgorithm('Kruskal', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Loop Selection
^^^^^^^^^^^^^^

Description
"""""""""""

Selects loops in a graph. |br| A loop is an edge that has the same source and target.

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Loop Selection', graph)

  # either create or get a boolean property from the graph to store the result of the algorithm
  resultSelection = graph.getBooleanProperty('resultSelection')
  success = graph.applyBooleanAlgorithm('Loop Selection', resultSelection, params)

  # or store the result of the algorithm in the default Tulip boolean property named 'viewSelection'
  success = graph.applyBooleanAlgorithm('Loop Selection', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Make Selection a Graph
^^^^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Extends the selection to have a graph. |br| All selected edges of the current graph will have their extremities selected (no dangling edges).

Parameters
""""""""""

+-----------+------------------------------+---------------+-------------+-----------------------------------------------+
| name      | type                         | default       | direction   | description                                   |
+===========+==============================+===============+=============+===============================================+
| selection | :class:`tlp.BooleanProperty` | viewSelection | input       | The property indicating the selected elements |
+-----------+------------------------------+---------------+-------------+-----------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Make Selection a Graph', graph)

  # set any input parameter value if needed
  # params['selection'] = ...

  # either create or get a boolean property from the graph to store the result of the algorithm
  resultSelection = graph.getBooleanProperty('resultSelection')
  success = graph.applyBooleanAlgorithm('Make Selection a Graph', resultSelection, params)

  # or store the result of the algorithm in the default Tulip boolean property named 'viewSelection'
  success = graph.applyBooleanAlgorithm('Make Selection a Graph', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Multiple Edges Selection
^^^^^^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Selects the multiple or parallel edges of a graph. |br| Two edges are considered as parallel if they have the same source/origin and the same target/destination.If it exists n edges between two nodes, only n-1 edges will be selected.

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Multiple Edges Selection', graph)

  # either create or get a boolean property from the graph to store the result of the algorithm
  resultSelection = graph.getBooleanProperty('resultSelection')
  success = graph.applyBooleanAlgorithm('Multiple Edges Selection', resultSelection, params)

  # or store the result of the algorithm in the default Tulip boolean property named 'viewSelection'
  success = graph.applyBooleanAlgorithm('Multiple Edges Selection', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Reachable Sub-Graph
^^^^^^^^^^^^^^^^^^^

Description
"""""""""""

Selects all nodes and edges at a maximum distance of 1 of the node of a given set of selected nodes.

Parameters
""""""""""

+-----------------+-------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------------+
| name            | type                          | default                                                                                                                                                                                                                                                   | direction   | description                                                                 |
+=================+===============================+===========================================================================================================================================================================================================================================================+=============+=============================================================================+
| edges direction | :class:`tlp.StringCollection` | output edges |br| |br| Values for that parameter: |br| output edges :  |istart| follow ouput edges (directed) |iend|  |br| input edges :  |istart| follow input edges (reverse-directed) |iend|  |br| all edges :  |istart| all edges (undirected) |iend| | input       | This parameter defines the navigation direction.                            |
+-----------------+-------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------------+
| starting nodes  | :class:`tlp.BooleanProperty`  | viewSelection                                                                                                                                                                                                                                             | input       | This parameter defines the starting set of nodes used to walk in the graph. |
+-----------------+-------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------------+
| distance        | integer                       | 5                                                                                                                                                                                                                                                         | input       | This parameter defines the maximal distance of reachable nodes.             |
+-----------------+-------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-------------+-----------------------------------------------------------------------------+

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Reachable Sub-Graph', graph)

  # set any input parameter value if needed
  # params['edges direction'] = ...
  # params['starting nodes'] = ...
  # params['distance'] = ...

  # either create or get a boolean property from the graph to store the result of the algorithm
  resultSelection = graph.getBooleanProperty('resultSelection')
  success = graph.applyBooleanAlgorithm('Reachable Sub-Graph', resultSelection, params)

  # or store the result of the algorithm in the default Tulip boolean property named 'viewSelection'
  success = graph.applyBooleanAlgorithm('Reachable Sub-Graph', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Spanning Dag
^^^^^^^^^^^^

Description
"""""""""""

Selects an acyclic subgraph of a graph.

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Spanning Dag', graph)

  # either create or get a boolean property from the graph to store the result of the algorithm
  resultSelection = graph.getBooleanProperty('resultSelection')
  success = graph.applyBooleanAlgorithm('Spanning Dag', resultSelection, params)

  # or store the result of the algorithm in the default Tulip boolean property named 'viewSelection'
  success = graph.applyBooleanAlgorithm('Spanning Dag', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

Spanning Forest
^^^^^^^^^^^^^^^

Description
"""""""""""

Selects a subgraph of a graph that is a forest (a set of trees).

Calling the plugin from Python
""""""""""""""""""""""""""""""

To call that plugin from Python, use the following code snippet::

  # get a dictionnary filled with the default plugin parameters values
  # graph is an instance of the tlp.Graph class
  params = tlp.getDefaultPluginParameters('Spanning Forest', graph)

  # either create or get a boolean property from the graph to store the result of the algorithm
  resultSelection = graph.getBooleanProperty('resultSelection')
  success = graph.applyBooleanAlgorithm('Spanning Forest', resultSelection, params)

  # or store the result of the algorithm in the default Tulip boolean property named 'viewSelection'
  success = graph.applyBooleanAlgorithm('Spanning Forest', params)

  # if the plugin declare any output parameter, its value can now be retrieved in the 'params' dictionnary

