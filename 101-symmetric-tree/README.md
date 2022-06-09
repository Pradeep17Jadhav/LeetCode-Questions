<h2><a href="https://leetcode.com/problems/symmetric-tree/">101. Symmetric Tree</a></h2><h3>Easy</h3><hr><div><p>Given the <code>root</code> of a binary tree, <em>check whether it is a mirror of itself</em> (i.e., symmetric around its center).</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<svg width="114" height="564" viewBox="0 0 114 564" preserveAspectRatio="xMinYMin" style="width: 900px;"><g transform="translate(-99.31578947368422, 112.8)" style="transform: none;"><g><line class="link__3Eq1" x1="156.31578947368422" y1="0" x2="85.26315789473685" y2="60"></line><line class="link__3Eq1" x1="156.31578947368422" y1="0" x2="227.3684210526316" y2="60"></line><line class="link__3Eq1" x1="85.26315789473685" y1="60" x2="42.631578947368425" y2="120"></line><line class="link__3Eq1" x1="85.26315789473685" y1="60" x2="127.89473684210527" y2="120"></line><line class="link__3Eq1" x1="227.3684210526316" y1="60" x2="213.1578947368421" y2="120"></line><g class="node__nu12" transform="translate(156.31578947368422, 0)"><circle r="1.2em"></circle><foreignObject width="2.4em" height="2.4em" x="-1.2em" y="-1.2em"><div class="node-text-container__KhIV"><span class="node-text__Cnsr" title="2">2</span></div></foreignObject></g><g class="node__nu12" transform="translate(85.26315789473685, 60)"><circle r="1.2em"></circle><foreignObject width="2.4em" height="2.4em" x="-1.2em" y="-1.2em"><div class="node-text-container__KhIV"><span class="node-text__Cnsr" title="3">3</span></div></foreignObject></g><g class="node__nu12" transform="translate(227.3684210526316, 60)"><circle r="1.2em"></circle><foreignObject width="2.4em" height="2.4em" x="-1.2em" y="-1.2em"><div class="node-text-container__KhIV"><span class="node-text__Cnsr" title="3">3</span></div></foreignObject></g><g class="node__nu12" transform="translate(42.631578947368425, 120)"><circle r="1.2em"></circle><foreignObject width="2.4em" height="2.4em" x="-1.2em" y="-1.2em"><div class="node-text-container__KhIV"><span class="node-text__Cnsr" title="4">4</span></div></foreignObject></g><g class="node__nu12" transform="translate(127.89473684210527, 120)"><circle r="1.2em"></circle><foreignObject width="2.4em" height="2.4em" x="-1.2em" y="-1.2em"><div class="node-text-container__KhIV"><span class="node-text__Cnsr" title="5">5</span></div></foreignObject></g><g class="node__nu12" transform="translate(213.1578947368421, 120)"><circle r="1.2em"></circle><foreignObject width="2.4em" height="2.4em" x="-1.2em" y="-1.2em"><div class="node-text-container__KhIV"><span class="node-text__Cnsr" title="5">5</span></div></foreignObject></g></g></g></svg>
<pre><strong>Input:</strong> root = [1,2,2,3,4,4,3]
<strong>Output:</strong> true
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/symtree2.jpg" style="width: 308px; height: 258px;">
<pre><strong>Input:</strong> root = [1,2,2,null,3,null,3]
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 1000]</code>.</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Could you solve it both recursively and iteratively?</div>