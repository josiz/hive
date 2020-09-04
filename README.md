# HIVE C
This repository includes all the projects made with C

## Piscine reloaded
First project with some basic C tasks

## Libft / Library
My own C library. Includes some usefull functions

## Get_next_line (GNL)
It is a function that reads a file and allows you to read a line ending with a newline character from a file descriptor. When you call the function again on the same file, it grabs the next line

## Fillit

Takes 4x4 tetris blocks as input and arranges them in such order that they fit in the smallest possible square.
The orientation of the blocks are not changed.

Run the Makefile and give the program valid blocks (samples included) as argument.

![Fillit blocks](https://lh3.googleusercontent.com/pw/ACtC-3cm6S9tTaXxgGrGswJ80K7nYy3QMHChMPPIsfW0GnyuR7Zmrd59X1_Wms9NcUugkLUW3NNzbef9lWxwCZ8kpmngcI6SJaswl82QW2ANs5Ozxg0vUtl6DDSe0nVWQu_7g8EG3wiwQNEzXF7vMew5l0bg=w247-h912-no)
![Fillit blocks2](https://lh3.googleusercontent.com/pw/ACtC-3cu-xQ0PQchyUreIctqNtEMgcGavh29X_H4D3YrJhqM67Eus5wPOgBp00tqQfYiAML6PdBpProYZ7p1n-PGpJCJP91oFcSq5R9Rg74hZj0RlYfwTjBhxiZ5JsJjrYMWBOnMnvS3KUXZLswBsEK3Qw38=w166-h912-no)

![Fillit solution](https://lh3.googleusercontent.com/pw/ACtC-3c6WYySttE9vmRu7xZrpn2rLhqDLOrKHyMLPYoyrwEj42IcpNJdSWs5gSaadkJvay3HFY20HVQ8GgDnghlotAajUe_wY-3KRywWbkhG_6kaTF8Eh37aTFNk77shvfHijmt_Yfn_01iqwqtI3uK5wBGh=w716-h438-no)

## FDF

A simple 3D height-map renderer. You can rotate with mouse, zoom, move and change the height of the models, color is defined by relative height in the map. There are three different projections as how you can view the model.

Run the Makefile and give the program a valid map (samples included) as argument.

![FDF42](https://lh3.googleusercontent.com/pw/ACtC-3cqVtX4pWRXbd8qQF7DM3Ss-lYTZhnpAc6xS3jKinlg-jEQu-7Z8m6BgZGowBrYiBR67cm1kzmL-0irxXaCVoQ9K2p1xX4IrRVjw9ShLfeGDK1DFaKdB9pIFptD2UgHaN1KgVEhKasql3jJ5riFerUf=w947-h565-no)

![FDF42](https://lh3.googleusercontent.com/pw/ACtC-3fuuA-TuF2eTGge8ftbbRWUJxLPb-BJOMnqwcPML4uhYDjz-45ih4Xutmn4NIY4AbBdIYzcdTRUUI5gZV44wnSwO6RlkXI1Sy9nt5ukAdufORvpXE65lwix513U1C5MZH0oevsZ8FNP2mqMeDRP1kZj=w946-h683-no)

![FDFpyra](https://lh3.googleusercontent.com/pw/ACtC-3cnuRkCoLZGg5DNsjMGC1c-B7qNdvVoH_Y2VZ6NKL9E27CmvjJob9MdAYet8Bp8ms8UrAsl6s8JjBtV9PMWK349Zye1tzQa8gfc_OFBk9yJEreHS6McILsct5Z4VCy6VNVojBVLrRQ3FR5skHm02Rpf=w946-h538-no)
Part of mars landscape
![FDFmars](https://lh3.googleusercontent.com/pw/ACtC-3dUZKEmRQQ4BRdJVIre0iTmjLPGY6iSKuxHo7_hbLmyRYb315JFjr5ZxJu2vhoei3rJQWmOUXUEE7ujrs4khHFGNk5jL52rkO_88yOhKPV-60b26VF2mHzf6fbb84buQHAjmTIPzh_tVACSicQXW72s=w946-h422-no)
Part of the landscape of southern Finland. Altiture differences enhanced...
![FDFESuomi](https://lh3.googleusercontent.com/pw/ACtC-3ejphUkKHT1o6SGHRowm1_ZqmYHHHfN8bfl65sec3v3Vp1aK2hX2w1LcWo1aaLlzaUOTu9KMoUnFGQVMSphBvhQzQZW2Q9kG1P1HXbWqlJbj9cmZwuxkXX7RfySgUcVe01FQ97vsiCPbqglnR3NYyxh=w946-h503-no)

## Printf

"homemade" version of the C-function printf, named ft_printf. Works with c, s, p, d, i, o, u, x, X and f. All flags #0-+ and space works. Width and precision also works. The only libc functions used: write(), malloc(), free() and exit().
