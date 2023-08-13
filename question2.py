import boto3
import csv

def check_admin_access(iam_client, role_name):
    response = iam_client.get_role_policy(RoleName=role_name, PolicyName='AdministratorAccess')
    return response is not None

def main():
    # Read the AWS credentials from credentials.json file
    with open('credentials.json') as f:
        credentials = json.load(f)

    # Create AWS IAM client
    iam_client = boto3.client('iam', aws_access_key_id=credentials['AKIASX4ZWNP4O4DFPAUN'],
                             aws_secret_access_key=credentials['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'])

    # Create AWS Lambda client
    lambda_client = boto3.client('lambda', aws_access_key_id=credentials['AKIASX4ZWNP4O4DFPAUN'],
                                 aws_secret_access_key=credentials['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'])

    lambda_functions = []

    # Fetch all Lambda functions
    regions = [region['RegionName'] for region in boto3.client('ec2').describe_regions()['Regions']]
    for region in regions:
        lambda_client = boto3.client('lambda', region_name=region, aws_access_key_id=credentials['AKIASX4ZWNP4O4DFPAUN'],
                                     aws_secret_access_key=credentials['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'])
        response = lambda_client.list_functions()
        functions = response.get('Functions', [])
        lambda_functions.extend(functions)

    # Check each Lambda function's attached IAM role for AdministratorAccess policy
    vulnerable_functions = []
    for function in lambda_functions:
        if 'Role' in function:
            role_name = function['Role'].split('/')[-1]
            if check_admin_access(iam_client, role_name):
                vulnerable_functions.append({
                    'FunctionName': function['FunctionName'],
                    'RoleName': role_name,
                    'Region': function['Region']
                })

    # Write the vulnerable functions to lambda.csv
    with open('lambda.csv', 'w', newline='') as csvfile:
        fieldnames = ['FunctionName', 'RoleName', 'Region']
        writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
        writer.writeheader()
        for function in vulnerable_functions:
            writer.writerow(function)

    print("saving the results in lambda.csv file")

if __name__ == "__main__":
    main()



