<?php
  error_reporting(E_ALL); 
  $db = mysqli_connect('localhost','root','Panthers16','prac_bank')
  or die('Error connecting to MySQL server.');
?>
<html>
 <head>
	<style>	
			#meals {
				    border: 1px solid black;
				    width: 30%;
				    text-align: left;
			}
			#row {
				width: 50%;
			}
		</style>

 </head>
 <body>
 <h1>Meals For Today</h1>

<table width="400" border="0" cellspacing="1" cellpadding="0">
<tr>
<td><form name="form1" method="post" action='<?=$_SERVER['PHP_SELF'] ?>'>

<?php
//Step2
date_default_timezone_set("EST");
$query = "SELECT * FROM meals Where day=\"" . date("l") . "\";";
mysqli_query($db, $query) or die('Error querying database.');
$result = mysqli_query($db, $query);

echo'	
      <tr>
	<th>Name</th>
	<th>Meal</th>
	<th>Eaten</th>
      </tr>';

while ($row = mysqli_fetch_array($result)) {
	$name=$row['name'];
	$meal=$row['meal'];

?> 	
<tr>
			<td id="row"><?php echo $name; ?></td>
			<td id="row"><?php echo $meal; ?></td>
			<td><input name="checkbox[]" type="checkbox" id="checkbox[]" value="<?php echo $name; ?>"></td>
		</tr>


<?php
}
?>

<tr>
<td colspan="5" align="center" bgcolor="#FFFFFF"><input name="delete" type="submit" id="delete" value="Delete"></td>
</tr>
<?php
if (count($_POST["checkbox"]) > 0){
	foreach($_POST["checkbox"] as $name){
		$query="DELETE FROM meals WHERE day=\"".date('l')."\" AND name=\"".$name."\";";
		echo $query; 
		$result= mysqli_query($db, $query) or die("Invalid query");
	}
}
?>
</tr>
</form>
</table>

</body>
</html>
