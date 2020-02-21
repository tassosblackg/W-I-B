# Create bg.txt and ball.txt files 
### For each kind of image set --negativeImages && for /BallImages (positive images aka :soccer:)
    by the term Positive images, we mean the actual images of the object to be recognized 
    where Negative images, are arbitrary images that are not showing the actual object [background images]
    
 > **NOTICE:** You only need to create these files if you modify or use a different dataset for positive and negative images!
 > otherwise use the already existing one in this repo.

* Build files script:
 
```
mkdir build

cd  build/ 
cmake ../

make -j4

./createfiles

```
