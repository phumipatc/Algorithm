---
layout: default
---

# Data Structure
* [Fenwick Tree](https://github.com/phumipatc/Algorithm/blob/master/Data_Structure/Fenwick_Tree.cpp)
```cpp
void upd(int idx,int v){
	for(;idx<=N;idx+=idx&=idx)
		tree[idx]+=v;
}
LL read(int idx,LL sum=0){
	for(;idx;idx-=idx&-idx)
		sum+=tree[idx];
	return sum;
}
```
* [Segment Tree](https://github.com/phumipatc/Algorithm/blob/master/Data_Structure/Segment_Tree.cpp)
```cpp
void upd_point(int l,int r,int now,int idx,int v){
	if(l == r){
		tree[now]+=v;
		return ;
	}
	int mid = (l+r)/2;
	if(idx<=mid)	upd_point(l,mid,now*2,idx,v);
	else			upd_point(mid+1,r,now*2+1,idx,v);
	tree[now]+=tree[now*2] + tree[now*2+1];
}
LL read_point(int l,int r,int now,int idx){
	if(l == r)	return tree[now];
	int mid = (l+r)/2;
	if(idx<=mid)	return read_point(l,mid,now*2,idx);
	else			return read_point(mid+1,r,now*2+1,idx);
}
```



Text can be **bold**, _italic_, or ~~strikethrough~~.

[Link to another page](./another-page.html).

There should be whitespace between paragraphs.

There should be whitespace between paragraphs. We recommend including a README, or a file with information about your project.

# Header 1

This is a normal paragraph following a header. GitHub is a code hosting platform for version control and collaboration. It lets you and others work together on projects from anywhere.

## Header 2

> This is a blockquote following a header.
>
> When something is important enough, you do it even if the odds are not in your favor.

### Header 3

```js
// Javascript code with syntax highlighting.
var fun = function lang(l) {
  dateformat.i18n = require('./lang/' + l)
  return true;
}
```


#### Header 4

*   This is an unordered list following a header.
*   This is an unordered list following a header.
*   This is an unordered list following a header.

##### Header 5

1.  This is an ordered list following a header.
2.  This is an ordered list following a header.
3.  This is an ordered list following a header.

###### Header 6

| head1        | head two          | three |
|:-------------|:------------------|:------|
| ok           | good swedish fish | nice  |
| out of stock | good and plenty   | nice  |
| ok           | good `oreos`      | hmm   |
| ok           | good `zoute` drop | yumm  |

### There's a horizontal rule below this.

* * *

### Here is an unordered list:

*   Item foo
*   Item bar
*   Item baz
*   Item zip

### And an ordered list:

1.  Item one
1.  Item two
1.  Item three
1.  Item four

### And a nested list:

- level 1 item
  - level 2 item
  - level 2 item
    - level 3 item
    - level 3 item
- level 1 item
  - level 2 item
  - level 2 item
  - level 2 item
- level 1 item
  - level 2 item
  - level 2 item
- level 1 item

### Small image

![Octocat](https://github.githubassets.com/images/icons/emoji/octocat.png)

### Large image

![Branching](https://guides.github.com/activities/hello-world/branching.png)


### Definition lists can be used with HTML syntax.

<dl>
<dt>Name</dt>
<dd>Godzilla</dd>
<dt>Born</dt>
<dd>1952</dd>
<dt>Birthplace</dt>
<dd>Japan</dd>
<dt>Color</dt>
<dd>Green</dd>
</dl>

```
Long, single-line code blocks should not wrap. They should horizontally scroll if they are too long. This line should be long enough to demonstrate this.
```

```
The final element.
```
